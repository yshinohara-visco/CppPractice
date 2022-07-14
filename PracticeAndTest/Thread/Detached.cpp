#include "Detached.h"

#include <functional>
#include <iostream>
#include <chrono>

namespace Detached
{
	//mainスレッドからこの関数を呼び、スリープ無しに終わるとendは表示されない
	//1500msスリープ、とかすると表示された
	//→プログラムの終了はdetachedスレッドの終了を待つわけではない　はず
	void Test1()
	{
		std::thread th1( [&]()
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );

				std::cout << "end" << std::endl;
			} );
		th1.detach();

		std::thread th2( [&]()
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 5000 ) );

				std::cout << "end" << std::endl;
			} );
		th2.detach();

		std::thread th3( [&]()
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 10000 ) );

				std::cout << "end" << std::endl;
			} );
		th3.join();
	}
}