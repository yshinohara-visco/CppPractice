#include "Future.h"
#include "Async.h"
#include "OnThreadEnd.h"
#include "Detached.h"

#include <thread>
#include <chrono>

int main()
{
	//HelloWorld::TestHello();
	//FuturePromiss::Test1();
	//Async::Test();
	OnThreadEnd::Test();
	
	//Detached::Test1();
	//std::this_thread::sleep_for( std::chrono::milliseconds( 1500 ) );
}