#include "OnThreadEnd.h"
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

namespace OnThreadEnd
{
	std::mutex _mtxCout;

	void Test()
	{
		std::vector<int> vecData1 = { 1,2,3 };
		std::vector<int> vecData2 = { 4,5,6 };
		std::vector<int> vecData3 = { 1,2,3,4,5 };
		std::vector<int> vecData4 = { 1,2,3,4,5,6,7,8,9,10 };

		std::thread th1( Worker, vecData1, OnEnd1 );
		std::thread th2( Worker, vecData2, OnEnd2 );
		std::thread th3( Worker, vecData3, OnEnd1 );
		std::thread th4( Worker, vecData4, OnEnd2 );

		th1.join();
		th2.join();
		th3.join();
		th4.join();

		std::cout << std::endl;

		MyThread mt1( vecData1, OnEnd1 );
		MyThread mt2( vecData2, OnEnd2 );
		MyThread mt3( vecData3, OnEnd1 );
		MyThread mt4( vecData4, OnEnd2 );

		mt1.Stop();
		mt3.Stop();
		mt2.Join();

		std::cout << std::endl;

		DetachedThread* dt1 = DetachedThread::Create( vecData1, OnEnd1 );
		DetachedThread* dt2 = DetachedThread::Create( vecData2, OnEnd2 );
		DetachedThread* dt3 = DetachedThread::Create( vecData3, OnEnd1 );
		DetachedThread* dt4 = DetachedThread::Create( vecData4, OnEnd2 );

		std::cout << "DetachedThread が終わる前に終了していいのか?" << std::endl;
		//->dt1～dt4の結果は出力されている
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
		
		//delete thisしても外から持つポインタの値はそのまま　そりゃそうか
		auto isNull = [&](DetachedThread* pDt)
		{
			if (pDt)
			{
				std::cout << "まだある" << std::endl;
			}
			else
			{
				std::cout << "もうない" << std::endl;
			}
		};
		isNull( dt1 );
		isNull( dt2 );
		isNull( dt3 );
		isNull( dt4 );
	}


	void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		int sum = 0;
		for (int data : vecData)
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
			sum += data;
		}

		onEnd( std::to_string( sum ) );
	}

	void OnEnd1( std::string str )
	{
		std::lock_guard<std::mutex> lock( _mtxCout );
		std::cout << "End1 : " << str << std::endl;
	}
	void OnEnd2( std::string str )
	{
		std::lock_guard<std::mutex> lock( _mtxCout );
		std::cout << "End2 : " << str << std::endl;
	}

	MyThread::MyThread( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		m_thread = std::thread( &MyThread::Worker, this, vecData, onEnd );
	}

	MyThread::~MyThread()
	{
		if (m_thread.joinable())
		{
			m_thread.join();
		}
	}

	void MyThread::Join()
	{
		m_thread.join();
	}

	void MyThread::Stop()
	{
		std::lock_guard<std::mutex> lock( m_mtxStop );
		m_isStopped = true;
	}

	void MyThread::Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		int sum = 0;
		for (int data : vecData)
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
			sum += data;
		}

		if (!IsStopped())
		{
			onEnd( std::to_string( sum ) );
		}
	}

	bool MyThread::IsStopped()
	{
		std::lock_guard<std::mutex> lock( m_mtxStop );
		return m_isStopped;
	}

	DetachedThread::DetachedThread( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		m_thread = std::thread( &DetachedThread::Worker, this, vecData, onEnd );
		m_thread.detach();
	}

	DetachedThread* DetachedThread::Create( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		return new DetachedThread( vecData, onEnd );
	}

	void DetachedThread::Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		int sum = 0;
		for (int data : vecData)
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
			sum += data;
		}

		onEnd( std::to_string( sum ) );

		delete this;
	}

}