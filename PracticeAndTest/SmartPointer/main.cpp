#include "AccessTime.h"
#include "ReturnUnique.h"
#include "ReleaseTest.h"

#include "../TimeLib/Timer.h"
#include <iostream>

int main()
{
	//AccessTime::Test();

	//double time = Time::MeasureTime( [&]() {1 + 1; }, 50, 1000000 );
	//std::cout << time << std::endl;

	//ReturnUnique::Test();

	ReleaseTest::Test();
}