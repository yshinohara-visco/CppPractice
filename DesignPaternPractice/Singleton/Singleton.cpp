#include "Singleton.h"

namespace
{

	constexpr int kMaxFinalizerSize = 256;
	std::mutex gMutex;
	int gNumFinalizerSize = 0;
	SingletonFinalizer::FinalizerFunc gFinalizers[kMaxFinalizerSize];
}


void SingletonFinalizer::addFinalizer(FinalizerFunc func)
{
	std::lock_guard<std::mutex> lock(gMutex);
	assert(gNumFinalizerSize < kMaxFinalizerSize); //Finalizerの数が限界を超えていないか確認
	gFinalizers[gNumFinalizerSize++] = func;
}


void SingletonFinalizer::finalize()
{
	std::lock_guard<std::mutex> lock(gMutex);
	for (int i = gNumFinalizerSize - 1; i >= 0  ; --i)
	{
		(*gFinalizers[i])();
	}
	gNumFinalizerSize = 0;
}