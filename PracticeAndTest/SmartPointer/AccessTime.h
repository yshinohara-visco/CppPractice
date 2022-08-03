#pragma once

/*
スマートポインタは生ポインタと比べるとアクセス時のオーバーヘッドが大きいらしい
実際どれくらいの差になるのか？

unique_ptrは削除する時、shared_ptrはカウンタの操作や削除をする時にオーバーヘッドがかかるらしい
アクセスを繰り返す時間を比べても意味は薄かった。
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