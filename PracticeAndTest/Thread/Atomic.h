#pragma once

#include <atomic>

namespace Atomic
{

	/*
	スピンロックとmutexで、ロックする時間が長いか短いかで使い分けがあるらしい
	スピンロックはロック、アンロックのコストが低いがロックを続けるコストが高い
	mutexはロック、アンロックのコストが高いがロックを続けるコストは低い　らしい
	短時間高頻度ロック→スピンロック　長時間低頻度ロック→mutex みたいな？
	ロック順と実行順の維持とかも関係ありそう
	*/
	class SpinLock
	{
	private:
		enum LockState
		{
			Locked,
			Unlocked,
		};

	public:
		SpinLock();

		void lock();
		void unlock();

	private:
		std::atomic<LockState> m_state;
	};

	void Test();

}