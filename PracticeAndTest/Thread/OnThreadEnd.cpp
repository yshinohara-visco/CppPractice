#include "OnThreadEnd.h"
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

namespace OnThreadEnd
{
	std::mutex _mtxCout;

	void Test()
	{
		std::vector<int> vecData1 = { 1,2,3 };
		std::vector<int> vecData2 = { 4,5,6 };
		std::vector<int> vecData3 = { 1,2,3,4,5 };
		std::vector<int> vecData4 = { 1,2,3,4,5,6,7,8,9,10 };

		std::thread th1( Worker, vecData1, OnEnd1 );
		std::thread th2( Worker, vecData2, OnEnd2 );
		std::thread th3( Worker, vecData3, OnEnd1 );
		std::thread th4( Worker, vecData4, OnEnd2 );

		th1.join();
		th2.join();
		th3.join();
		th4.join();
	}


	void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd )
	{
		int sum = 0;
		for (int data : vecData)
		{
			std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
			sum += data;
		}

		onEnd( std::to_string( sum ) );
	}

	void OnEnd1( std::string str )
	{
		std::lock_guard<std::mutex> lock( _mtxCout );
		std::cout << "End1 : " << str << std::endl;
	}
	void OnEnd2( std::string str )
	{
		std::lock_guard<std::mutex> lock( _mtxCout );
		std::cout << "End2 : " << str << std::endl;
	}
}