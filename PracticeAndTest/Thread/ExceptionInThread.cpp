#include "ExceptionInThread.h"
#include <iostream>
#include <thread>
#include <optional>
#include <future>

/*
�X���b�h���ŋN������O�͑��̃X���b�h�܂œ`���Ȃ�
���ꕨ������Ēu������feature��p���鎖�Ŏ����o�������ł���
�ǂ���ɂ���X���b�h���ň��cathc����K�v������炵��
�X���b�h����cathc������O�������o�������P�[�X�͗L��̂��H���̏�ŏ������ς܂���̂ł́H
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

	//���ʂɗ�O���N������
	void Test1()
	{
		try
		{
			throw MyException( "Test1-1" ); //��O�𓊂���
		}
		catch (const MyException& e) //�L���b�`���ĕ\��
		{
			std::cout << "Catch MyException. Message is [" << e.GetMessage() << "]" << std::endl;
		}

		throw MyException( "Test1-2" ); //�ēx��O�𓊂��遨�����Ŏ~�܂�
	}

	//�X���b�h���ŗ�O���N������
	void Test2()
	{
		try
		{
			std::thread th( [&]()
				{
					try
					{
						throw MyException( "Test2-1" ); //��O�𓊂���
					}
					catch (const MyException& e) //�L���b�`���ĕ\��
					{
						std::cout << "Catch MyException in th. Message is [" << e.GetMessage() << "]" << std::endl;
					}

					throw MyException( "Test2-2" ); //�ēx��O�𓊂��遨Test1�Ƃ͈Ⴄ�`�Ŏ~�܂�
				} );

			th.join();
		}
		catch (const std::exception&) //�����ŃL���b�`���邱�Ƃ͂ł��Ȃ�
		{
			std::cout << "catch" << std::endl;
		}


		std::cout << "End" << std::endl;
	}

	//�X���b�h���̗�O���O�Ɏ����o�� �l�b�g�Ō���������i�������j
	void Test3()
	{
		std::optional<MyException> ex;

		std::thread th( [&]()
			{
				try
				{
					throw MyException( "Test3-1" ); //��O�𓊂���
				}
				catch (const MyException& e)
				{
					std::cout << "catch" << std::endl;
					ex = e; //���
				}
			} );
		th.join();

		if (ex)
		{
			std::cout << "Catch MyException in th. Message is [" << ex->GetMessage() << "]" << std::endl;
		}
	}

	//promise,feature�œn���@��₱�������Y��
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