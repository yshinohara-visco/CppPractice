#include "ReleaseTest.h"

#include <iostream>
#include <vector>

namespace ReleaseTest
{
	Checker::Checker()
	{
		id = ++num;
		std::cout << "Construct " << id << std::endl;
	}

	Checker::~Checker()
	{
		std::cout << "Destruct " << id << std::endl;
		num--;
	}

	void Test()
	{
		{
			auto sp = makeUC;

			sp = makeUC;
			sp = makeUC;
		}
		std::cout << "------0" << std::endl;

		std::vector<upChecker> vecUC;
		for (size_t i = 0; i < 5; i++)
		{
			vecUC.push_back( makeUC );
		}
		std::cout << "------1" << std::endl;
		{
			std::vector<upChecker> vecUC2;
			for (size_t i = 0; i < 5; i++)
			{
				vecUC2.push_back( makeUC );
			}
			std::cout << "------2" << std::endl;

			vecUC.swap( vecUC2 );
			std::cout << "------3" << std::endl;
		}
		std::cout << "------4" << std::endl;
	}
}

