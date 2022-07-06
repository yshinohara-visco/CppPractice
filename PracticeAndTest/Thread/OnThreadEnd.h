#pragma once
#include <functional>
#include <string>
#include <vector>
#include <mutex>

namespace OnThreadEnd
{
	void Test();

	void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd );

	void OnEnd1( std::string str );
	void OnEnd2( std::string str );

	/*
	* 中断可能なスレッド
	* killは危険すぎるらしいのでチェックポイントを設ける形
	* 実際はonEndとそれまでの分割や、チェックポイントを増やすのに苦労しそう
	*/
	class MyThread
	{
	public:
		MyThread( std::vector<int> vecData, std::function<void( std::string )> onEnd );
		~MyThread(); //joinしてなかったらjoin

		void Join(); //明示的join
		void Stop(); //中断（onEndは実行しない）
		bool IsStopped(); //中断指示が出たか

	private:
		std::thread m_thread;
		std::mutex m_mtxStop;
		bool m_isStopped = false;

		void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd );
	};

	class DetachedThread
	{
	private:
		DetachedThread( std::vector<int> vecData, std::function<void( std::string )> onEnd );

	public:
		static DetachedThread* Create( std::vector<int> vecData, std::function<void( std::string )> onEnd );

	private:
		std::thread m_thread;

		void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd );
	};
}