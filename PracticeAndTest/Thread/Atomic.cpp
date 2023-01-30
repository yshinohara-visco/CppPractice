#include "Atomic.h"
#include "../TimeLib/Timer.h"

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

	SpinLock::SpinLock()
		:m_state( Unlocked )
	{}

	void SpinLock::lock()
	{
		while (m_state.exchange( Locked, std::memory_order_acquire ) == Locked)
		{
			//アンロックまで待機
		}
	}

	void SpinLock::unlock()
	{
		m_state.store( Unlocked, std::memory_order_release );
	}


	void Test()
	{
		Time::Timer timer;

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

		timer.Start();
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
		std::cout << "count : " << count << std::endl
			<< "  time : " << timer.Get() << "ms" << std::endl << std::endl;


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

		timer.Start();
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
		std::cout << "countAtomic : " << countAtomic << std::endl
			<< "  time : " << timer.Get() << "ms" << std::endl << std::endl;

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
				// と思ったけどリリースビルドしたら早くなった
				std::lock_guard<std::mutex> lock( mtxCount );
				countMutex++;
			}
		};

		timer.Start();
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
		std::cout << "countMutex : " << countMutex << std::endl
			<< "  time : " << timer.Get() << "ms" << std::endl << std::endl;

		/*
		スピンロックを使用する場合
		*/
		int countSpin = 0;
		SpinLock spinLock;

		auto funcAddSpin = [&]()
		{
			for (size_t i = 0; i < time; i++)
			{
				//クリティカルセクションになり平行して実行されない
				//!!mutexより早かったリ遅かったりする!! 実装間違えた？
				// リリースビルドでもあまり変わらなかった
				std::lock_guard<SpinLock> lock( spinLock );
				countSpin++;
			}
		};

		timer.Start();
		std::thread ts1( funcAddSpin );
		std::thread ts2( funcAddSpin );
		std::thread ts3( funcAddSpin );
		std::thread ts4( funcAddSpin );
		std::thread ts5( funcAddSpin );
		ts1.join();
		ts2.join();
		ts3.join();
		ts4.join();
		ts5.join();

		std::cout << "countSpin : " << countSpin << std::endl
			<< "  time : " << timer.Get() << "ms" << std::endl << std::endl;
	}

	/*
	結果1 デバッグビルド
	count : 14766312
	  time : 334.601ms

	countAtomic : 50000000
	  time : 1215.12ms

	countMutex : 50000000
	  time : 9981.38ms

	countSpin : 50000000
	  time : 8408.98ms

	結果2　リリースビルド
	count : 23420771
	  time : 183.685ms

	countAtomic : 50000000
	  time : 1193.79ms

	countMutex : 50000000
	  time : 1395.42ms

	countSpin : 50000000
	  time : 8990.61ms
	*/

}