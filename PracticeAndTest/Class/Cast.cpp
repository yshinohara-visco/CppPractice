#include "Cast.h"
#include <iostream>

namespace Cast
{
	void Test()
	{
		int i = 123;
		double d = 10.1;

		Holder holder;

		holder.Set( i );
		std::cout << "1 " << holder.Get<int>() << std::endl;

		holder.Set( d );
		std::cout << "2 " << holder.Get<double>() << std::endl;

		holder.Set( i );
		std::cout << "3 " << holder.Get<double>() << std::endl;

		holder.Set( d );
		std::cout << "4 " << holder.Get<int>() << std::endl;
	}
}