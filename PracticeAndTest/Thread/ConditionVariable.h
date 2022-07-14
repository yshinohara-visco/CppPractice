#pragma once

#include <condition_variable>
#include <mutex>



namespace ConditionVariable
{
	/*
	wait()は実行待機キューに自身を追加する。
	notify_one(), notify_all()は実行待機キューにあるスレッドの待機を解除する。
	とみなせる。

	のでm_isDataReadyを使わずに単にwait,notidyのみ使うと、notifyした後にwaitすると永遠に待ち続ける
	ような問題が起きるらしい。

	boolとかを参照してwhileループして待つポーリング方式よりも実行効率が良いはず
	処理系や状況によって例外はあるかもしれない
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

	//condition_variableを使用して開始、停止、中断、再開を出来るようにしたスレッド
	//多分合っている？
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

