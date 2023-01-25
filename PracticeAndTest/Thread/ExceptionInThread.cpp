#include "ExceptionInThread.h"
#include <iostream>
#include <thread>
#include <optional>
#include <future>

/*
スレッド内で起きた例外は他のスレッドまで伝わらない
入れ物を作って置いたりfeatureを用いる事で持ち出す事ができる
どちらにせよスレッド内で一回cathcする必要があるらしい
スレッド内でcathcした例外を持ち出したいケースは有るのか？その場で処理を済ませるのでは？
*/

namespace ExceptionInThread
{
	MyException::MyException( std::string message )
		:m_msg( message )
	{}

	std::string MyException::GetMessage() const
	{
		return m_msg;
	}

	//普通に例外が起きた時
	void Test1()
	{
		try
		{
			throw MyException( "Test1-1" ); //例外を投げて
		}
		catch (const MyException& e) //キャッチして表示
		{
			std::cout << "Catch MyException. Message is [" << e.GetMessage() << "]" << std::endl;
		}

		throw MyException( "Test1-2" ); //再度例外を投げる→ここで止まる
	}

	//スレッド内で例外が起きた時
	void Test2()
	{
		try
		{
			std::thread th( [&]()
				{
					try
					{
						throw MyException( "Test2-1" ); //例外を投げて
					}
					catch (const MyException& e) //キャッチして表示
					{
						std::cout << "Catch MyException in th. Message is [" << e.GetMessage() << "]" << std::endl;
					}

					throw MyException( "Test2-2" ); //再度例外を投げる→Test1とは違う形で止まる
				} );

			th.join();
		}
		catch (const std::exception&) //ここでキャッチすることはできない
		{
			std::cout << "catch" << std::endl;
		}


		std::cout << "End" << std::endl;
	}

	//スレッド内の例外を外に持ち出す ネットで見かけたやつ（怪しい）
	void Test3()
	{
		std::optional<MyException> ex;

		std::thread th( [&]()
			{
				try
				{
					throw MyException( "Test3-1" ); //例外を投げて
				}
				catch (const MyException& e)
				{
					std::cout << "catch" << std::endl;
					ex = e; //代入
				}
			} );
		th.join();

		if (ex)
		{
			std::cout << "Catch MyException in th. Message is [" << ex->GetMessage() << "]" << std::endl;
		}
	}

	//promise,featureで渡す　ややこしいが綺麗
	void Test4()
	{
		std::promise<std::string> p1;
		std::promise<std::string> p2;

		auto f1 = p1.get_future();
		auto f2 = p2.get_future();

		auto setValue = []( std::promise<std::string> p )
		{
			p.set_value( "setValue" );
		};
		auto setException = []( std::promise<std::string> p )
		{
			try
			{
				throw MyException( "Test4" );
			}
			catch (const std::exception&)
			{
				p.set_exception( std::current_exception() );
			}
		};
		std::thread th1( setValue, std::move( p1 ) );
		std::thread th2( setException, std::move( p2 ) );

		try
		{
			std::cout << "th1:" << f1.get() << std::endl;
			std::cout << "th2:" << f2.get() << std::endl;
		}
		catch (const MyException& e)
		{
			std::cout << "catch:" << e.GetMessage() << std::endl;
		}

		th1.join();
		th2.join();
	}
}