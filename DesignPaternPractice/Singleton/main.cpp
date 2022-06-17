#include "Singleton.h"

#include <iostream>

int main()
{
	//int i = Singleton<int>::get_instance();
	//double d = Singleton<double>::get_instance();


	#define GET_INT Singleton<int>::get_instance
	#define GET_DOUBLE Singleton<double>::get_instance

	GET_INT() = 5;
	GET_DOUBLE() = 10.1;

	std::cout << "i:" << GET_INT() << " d:" << GET_DOUBLE() << std::endl;

	SingletonFinalizer::finalize();

	return 0;
}