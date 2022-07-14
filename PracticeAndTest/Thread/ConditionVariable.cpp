#include "ConditionVariable.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace ConditionVariable
{
	void ProcessData::PrepareDataForProcessing()
	{
		std::cout << "Prepare" << std::endl;
		//準備処理
		std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

		//フラグ立て
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isDataReady = true;
		}

		//準備完了したのでスレッドを起床させる
		m_cv.notify_one();
	}

	void ProcessData::WaitForDataToProcess()
	{
		std::cout << "Wait" << std::endl;
		std::unique_lock<std::mutex> lock( m_mtx );

		//データの準備が出来るまで待機してから処理する
		m_cv.wait( lock, [this] {return m_isDataReady; } );
		/*
		while (!pred()) {
			 wait(lock);
		}
		と等価らしい。
		式がfalseを返す限りwaitする
		trueを返すなら待たない
		*/


		Process();
	}

	void ProcessData::Process()
	{
		//データを処理する
		std::cout << "Process data" << std::endl;
	}


	void Test1()
	{
		ProcessData p;

		std::thread t1( [&] { p.PrepareDataForProcessing(); } );
		std::thread t2( [&] { p.WaitForDataToProcess(); } );

		t1.join();
		t2.join();

		std::cout << std::endl;

		//m_isDataReadyを使っているので順番は問わない
		ProcessData p2;

		std::thread t3( [&] { p2.WaitForDataToProcess(); } );
		std::thread t4( [&] { p2.PrepareDataForProcessing(); } );

		t3.join();
		t4.join();
	}

	//------------------------

	//デストラクタではスレッドを終了する
	myThread::~myThread()
	{
		Wait();
	}

	//スレッドが無ければ作成して処理を開始
	bool myThread::Start()
	{
		if (m_thread.joinable())
		{
			return false;
		}
		m_isPause = m_isJoin = false;
		m_thread = std::thread( &myThread::ThreadProcess, this );
		return true;
	}

	//スレッドが有れば停止要求を送り、終わるのを待つ
	bool myThread::Wait()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		//停止フラグを立てる
		DoWait();
		
		m_thread.join();
		return true;
	}

	//スレッドの中断要求を送る
	bool myThread::Pause()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		DoPause( true );
		return true;
	}

	//スレッドの再開要求を送る
	bool myThread::Resume()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		DoPause( false );
		return true;
	}

	//スレッドの中のチェックポイント
	bool  myThread::TestDestroy()
	{
		std::unique_lock<std::mutex> lock( m_mtx );

		//Pauseなら一時停止
		m_cv.wait( lock, [&]
			{
				return !m_isPause;
			} );

		return m_isJoin;
	}

	//実際の中断、再開処理
	void  myThread::DoPause( bool pause )
	{
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isPause = pause;
		}
		
		m_cv.notify_one();
	}

	//実際の終了処理
	void  myThread::DoWait()
	{
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isPause = false;
			m_isJoin = true;
		}

		m_cv.notify_one();
	}

	//スレッド処理
	//中断や停止への対応はTestDestroy()で行われる。
	void Printer::ThreadProcess()
	{
		while (!TestDestroy())
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
			std::cout << m_i++;
		}
	}

	//2秒おきに止めたり動かしたりするテスト
	void Test2()
	{
		{
			Printer p;

			//開始して2秒待つ
			std::cout << std::endl << "Start" << std::endl;
			p.Start();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );


			//停止して2秒待つ
			p.Wait();
			std::cout << std::endl << "Wait" << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

			//再開して2秒待つ
			std::cout << std::endl << "Start" << std::endl;
			p.Start();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
			
			//一時停止して2秒待つ
			p.Pause();
			std::cout << std::endl << "Pause" << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

			//再開して2秒待つ
			std::cout << std::endl << "Resume" << std::endl;
			p.Resume();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
		}

		std::cout << std::endl << "End" << std::endl;
	}
}