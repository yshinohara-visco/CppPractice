#include "ConditionVariable.h"

#include <iostream>
#include <thread>
#include <chrono>

namespace ConditionVariable
{
	void ProcessData::PrepareDataForProcessing()
	{
		std::cout << "Prepare" << std::endl;
		//��������
		std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

		//�t���O����
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isDataReady = true;
		}

		//�������������̂ŃX���b�h���N��������
		m_cv.notify_one();
	}

	void ProcessData::WaitForDataToProcess()
	{
		std::cout << "Wait" << std::endl;
		std::unique_lock<std::mutex> lock( m_mtx );

		//�f�[�^�̏������o����܂őҋ@���Ă��珈������
		m_cv.wait( lock, [this] {return m_isDataReady; } );
		/*
		while (!pred()) {
			 wait(lock);
		}
		�Ɠ����炵���B
		����false��Ԃ�����wait����
		true��Ԃ��Ȃ�҂��Ȃ�
		*/


		Process();
	}

	void ProcessData::Process()
	{
		//�f�[�^����������
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

		//m_isDataReady���g���Ă���̂ŏ��Ԃ͖��Ȃ�
		ProcessData p2;

		std::thread t3( [&] { p2.WaitForDataToProcess(); } );
		std::thread t4( [&] { p2.PrepareDataForProcessing(); } );

		t3.join();
		t4.join();
	}

	//------------------------

	//�f�X�g���N�^�ł̓X���b�h���I������
	myThread::~myThread()
	{
		Wait();
	}

	//�X���b�h��������΍쐬���ď������J�n
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

	//�X���b�h���L��Β�~�v���𑗂�A�I���̂�҂�
	bool myThread::Wait()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		//��~�t���O�𗧂Ă�
		DoWait();
		
		m_thread.join();
		return true;
	}

	//�X���b�h�̒��f�v���𑗂�
	bool myThread::Pause()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		DoPause( true );
		return true;
	}

	//�X���b�h�̍ĊJ�v���𑗂�
	bool myThread::Resume()
	{
		if (false == m_thread.joinable())
		{
			return false;
		}

		DoPause( false );
		return true;
	}

	//�X���b�h�̒��̃`�F�b�N�|�C���g
	bool  myThread::TestDestroy()
	{
		std::unique_lock<std::mutex> lock( m_mtx );

		//Pause�Ȃ�ꎞ��~
		m_cv.wait( lock, [&]
			{
				return !m_isPause;
			} );

		return m_isJoin;
	}

	//���ۂ̒��f�A�ĊJ����
	void  myThread::DoPause( bool pause )
	{
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isPause = pause;
		}
		
		m_cv.notify_one();
	}

	//���ۂ̏I������
	void  myThread::DoWait()
	{
		{
			std::lock_guard<std::mutex> lock( m_mtx );
			m_isPause = false;
			m_isJoin = true;
		}

		m_cv.notify_one();
	}

	//�X���b�h����
	//���f���~�ւ̑Ή���TestDestroy()�ōs����B
	void Printer::ThreadProcess()
	{
		while (!TestDestroy())
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
			std::cout << m_i++;
		}
	}

	//2�b�����Ɏ~�߂��蓮�������肷��e�X�g
	void Test2()
	{
		{
			Printer p;

			//�J�n����2�b�҂�
			std::cout << std::endl << "Start" << std::endl;
			p.Start();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );


			//��~����2�b�҂�
			p.Wait();
			std::cout << std::endl << "Wait" << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

			//�ĊJ����2�b�҂�
			std::cout << std::endl << "Start" << std::endl;
			p.Start();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
			
			//�ꎞ��~����2�b�҂�
			p.Pause();
			std::cout << std::endl << "Pause" << std::endl;
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

			//�ĊJ����2�b�҂�
			std::cout << std::endl << "Resume" << std::endl;
			p.Resume();
			std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
		}

		std::cout << std::endl << "End" << std::endl;
	}
}