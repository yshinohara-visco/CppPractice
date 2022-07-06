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
		std::thread th( [&]()
			{
				std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );

				std::cout << "end" << std::endl;
			} );
		th.detach();
	}
}