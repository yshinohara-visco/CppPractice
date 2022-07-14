#pragma once

#include <condition_variable>
#include <mutex>



namespace ConditionVariable
{
	/*
	wait()�͎��s�ҋ@�L���[�Ɏ��g��ǉ�����B
	notify_one(), notify_all()�͎��s�ҋ@�L���[�ɂ���X���b�h�̑ҋ@����������B
	�Ƃ݂Ȃ���B

	�̂�m_isDataReady���g�킸�ɒP��wait,notidy�̂ݎg���ƁAnotify�������wait����Ɖi���ɑ҂�������
	�悤�Ȗ�肪�N����炵���B

	bool�Ƃ����Q�Ƃ���while���[�v���đ҂|�[�����O�����������s�������ǂ��͂�
	�����n��󋵂ɂ���ė�O�͂��邩������Ȃ�
	*/
	class ProcessData
	{
	public:
		void PrepareDataForProcessing();
		void WaitForDataToProcess();

	private:
		std::mutex m_mtx;
		std::condition_variable m_cv;
		bool m_isDataReady = false;

		void Process();
	};

	void Test1();

	//condition_variable���g�p���ĊJ�n�A��~�A���f�A�ĊJ���o����悤�ɂ����X���b�h
	//���������Ă���H
	class myThread
	{
	public:
		~myThread();

		bool Start();
		bool Wait();

		bool Pause();
		bool Resume();

	protected:
		virtual void ThreadProcess() = 0;
		bool TestDestroy();

	private:
		std::mutex m_mtx;
		std::condition_variable m_cv;
		bool m_isPause = false;
		bool m_isJoin = false;

		std::thread m_thread;

		void DoPause( bool pause );
		void DoWait();
	};

	class Printer : public myThread
	{
	public:

	private:
		int m_i = 0;

		void ThreadProcess() override;
	};

	void Test2();
};

