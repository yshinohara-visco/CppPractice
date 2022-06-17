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
	assert(gNumFinalizerSize < kMaxFinalizerSize); //Finalizer‚Ì”‚ªŒÀŠE‚ð’´‚¦‚Ä‚¢‚È‚¢‚©Šm”F
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