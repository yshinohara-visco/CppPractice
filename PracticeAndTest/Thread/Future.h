#pragma once

#include <future>

namespace FuturePromiss
{
	void Test1();

	//スレッド内で行う処理
	int ComputeSomthing( bool throwError );

	//スレッド処理
	void Worker( std::promise<int> p, bool throwError );
}

