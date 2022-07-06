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
		std::thread th( [&]()
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );

				std::cout << "end" << std::endl;
			} );
		th.detach();
	}
}