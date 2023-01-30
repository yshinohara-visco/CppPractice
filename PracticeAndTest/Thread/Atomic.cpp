#include "Atomic.h"

#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>

/*
スレッド間で単一の変数にしか触らない時や、mutexによるクリティカルセクションを
作りたくない時に使用するらしい。
loadやstoreに引数を付けて実行順序に制限を付けることでメモリバリアを実現するとか
下記の処理をatomicとmutexで比べるとかなり時間に差が付いた

スレッドで～した結果を元にboolフラグを立てたり折ったり～でboolをatomicにするのは有りなのか？
～する処理内容にもよるのか？
*/

namespace Atomic
{
	void Test()
	{
		/*
		Atomic 無しの場合
		*/
		int count = 0;
		const size_t time = 10000000;

		auto funcAdd = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				count++; //並行して実行され得る→値が不正に
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

		//countの値はtime*5にならない
		std::cout << "count : " << count << std::endl;


		/*
		Atomic 有りの場合
		*/
		std::atomic<int> countAtomic( 0 );

		auto funcAddAtomic = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				countAtomic++; //並行して実行されない→確実に1加算
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

		//countの値はtime*5になる
		std::cout << "countAtomic : " << countAtomic << std::endl;

		/*
		mutexを使用する場合
		*/
		int countMutex = 0;
		std::mutex mtxCount;

		auto funcAddMutex = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				//クリティカルセクションになり平行して実行されない
				//!!atomicと比べるとかなり処理時間が長い!!
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

		//countの値はtime*5になる
		std::cout << "countMutex : " << countMutex << std::endl;
	}
}