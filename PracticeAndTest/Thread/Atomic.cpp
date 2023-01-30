#include "Atomic.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>

/*
�X���b�h�ԂŒP��̕ϐ��ɂ����G��Ȃ�����Amutex�ɂ��N���e�B�J���Z�N�V������
��肽���Ȃ����Ɏg�p����炵���B
load��store�Ɉ�����t���Ď��s�����ɐ�����t���邱�ƂŃ������o���A����������Ƃ�
���L�̏�����atomic��mutex�Ŕ�ׂ�Ƃ��Ȃ莞�Ԃɍ����t����

�X���b�h�Ł`�������ʂ�����bool�t���O�𗧂Ă���܂�����`��bool��atomic�ɂ���̂͗L��Ȃ̂��H
�`���鏈�����e�ɂ����̂��H
*/

namespace Atomic
{
	void Test()
	{
		/*
		Atomic �����̏ꍇ
		*/
		int count = 0;
		const size_t time = 10000000;

		auto funcAdd = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				count++; //���s���Ď��s���꓾�遨�l���s����
			}
		};

		std::thread t1( funcAdd );
		std::thread t2( funcAdd );
		std::thread t3( funcAdd );
		std::thread t4( funcAdd );
		std::thread t5( funcAdd );
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();

		//count�̒l��time*5�ɂȂ�Ȃ�
		std::cout << "count : " << count << std::endl;


		/*
		Atomic �L��̏ꍇ
		*/
		std::atomic<int> countAtomic( 0 );

		auto funcAddAtomic = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				countAtomic++; //���s���Ď��s����Ȃ����m����1���Z
			}
		};

		std::thread ta1( funcAddAtomic );
		std::thread ta2( funcAddAtomic );
		std::thread ta3( funcAddAtomic );
		std::thread ta4( funcAddAtomic );
		std::thread ta5( funcAddAtomic );
		ta1.join();
		ta2.join();
		ta3.join();
		ta4.join();
		ta5.join();

		//count�̒l��time*5�ɂȂ�
		std::cout << "countAtomic : " << countAtomic << std::endl;

		/*
		mutex���g�p����ꍇ
		*/
		int countMutex = 0;
		std::mutex mtxCount;

		auto funcAddMutex = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				//�N���e�B�J���Z�N�V�����ɂȂ蕽�s���Ď��s����Ȃ�
				//!!atomic�Ɣ�ׂ�Ƃ��Ȃ菈�����Ԃ�����!!
				std::lock_guard<std::mutex> lock( mtxCount );
				countMutex++;
			}
		};

		std::thread tm1( funcAddMutex );
		std::thread tm2( funcAddMutex );
		std::thread tm3( funcAddMutex );
		std::thread tm4( funcAddMutex );
		std::thread tm5( funcAddMutex );
		tm1.join();
		tm2.join();
		tm3.join();
		tm4.join();
		tm5.join();

		//count�̒l��time*5�ɂȂ�
		std::cout << "countMutex : " << countMutex << std::endl;
	}
}