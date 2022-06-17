#include "Future.h"
#include <iostream>
#include <chrono>

namespace FuturePromiss
{
	void Test1()
	{
		//非同期に受け渡される値や例外を設定するためのクラス
		//値か例外の設定どちらかを一回だけ可能
		std::promise<int> p1;
		std::promise<int> p2;

		//std::promiseで設定された値や例外を非同期に受け取るためのクラス
		std::future<int> f1 = p1.get_future();
		std::future<int> f2 = p2.get_future();

		std::thread th1( Worker, std::move( p1 ), false );
		std::thread th2( Worker, std::move( p2 ), true );
		std::cout << "Start thread" << std::endl;

		std::cout << "Try get 1 : ";
		try
		{
			//get()する時点で値がセットされるまで待つ
			std::cout << f1.get() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Try get 2 : ";
		try
		{
			//get()する時点で値がセットされるまで待つ
			std::cout << f2.get() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		th1.join();
		th2.join();
	}

	//スレッド内で行う処理
	int ComputeSomthing( bool throwError )
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );
		if (throwError)
		{
			throw(std::exception( "hogeeee" ));
		}
		else
		{
			return 2000;
		}
	}

	//スレッド処理
	void Worker( std::promise<int> p, bool throwError )
	{
		try
		{
			//何か処理をして結果をPromiseに設定する
			p.set_value( ComputeSomthing( throwError ) );
		}
		catch (const std::exception&)
		{
			//例外が発生したら例外をPromiseに設定する
			p.set_exception( std::current_exception() );
		}
	}
}