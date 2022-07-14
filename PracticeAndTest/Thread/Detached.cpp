#include "Detached.h"

#include <functional>
#include <iostream>
#include <chrono>

namespace Detached
{
	//main�X���b�h���炱�̊֐����ĂсA�X���[�v�����ɏI����end�͕\������Ȃ�
	//1500ms�X���[�v�A�Ƃ�����ƕ\�����ꂽ
	//���v���O�����̏I����detached�X���b�h�̏I����҂킯�ł͂Ȃ��@�͂�
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