#pragma once

/*
スマートポインタは生ポインタと比べるとアクセス時のオーバーヘッドが大きいらしい
実際どれくらいの差になるのか？
*/

#include <chrono>

namespace AccessTime
{
	class Timer
	{
	public:
		void Start();
		double Get();

	private:
		std::chrono::system_clock::time_point m_start;
	};

	void Test();
}