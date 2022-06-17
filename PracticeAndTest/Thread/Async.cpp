#include "Async.h"
#include <future>
#include <chrono>
#include <iostream>

namespace Async
{
	void Test()
	{
		std::vector<int> data = { 1,2,3,4,5 };

		//Worker()を非同期に実行する
		// 第一引数：enum class
		std::future<int> f =
			std::async( std::launch::async, Worker, data );

		try
		{
			//非同期処理の結果を取得する
			std::cout << f.get() << std::endl;
		}
		catch (const std::exception&)
		{
			//Worker()で起きた例外を補足
		}
	}

	int Worker( const std::vector<int>& data )
	{
		int sum = 0;
		for (int i : data)
		{
			//時間がかかる処理
			std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
			sum += i;
		}
		return sum;
	}
}