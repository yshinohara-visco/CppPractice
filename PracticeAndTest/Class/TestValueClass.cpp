#include "TestValueClass.h"

#include <iostream>

namespace TestValueClass
{
	void TestMethod1()
	{
		HOGE1 h1;
		h1.Set( 50 );
		std::cout << "h1 : " << h1.Get() << std::endl;

		h1.Set( 110 );
		std::cout << "h1 : " << h1.Get() << std::endl;

		h1.Add( 60 );
		std::cout << "h1 : " << h1.Get() << std::endl;

		HOGE2 h2;
		h2.Set( 50 );
		std::cout << "h2 : " << h2.Get() << std::endl;

		try
		{
			h2.Set( 110 );
			std::cout << "h2 : " << h2.Get() << std::endl;
		}
		catch (const const char* c)
		{
			std::cout << "error : " << c << std::endl;
		}

		try
		{
			h2.Add( 60 );
			std::cout << "h2 : " << h2.Get() << std::endl;
		}
		catch (const const char* c)
		{
			std::cout << "error : " << c << std::endl;
		}

		HOGE3 h3;
		h3.Set( Score( 50 ) );
		std::cout << "h3 : " << h3.Get()->Value() << std::endl;

		try
		{
			h3.Set( Score( 110 ) );
			std::cout << "h3 : " << h3.Get()->Value() << std::endl;
		}
		catch (const const char* c)
		{
			std::cout << "error : " << c << std::endl;
		}

		try
		{
			h3.Add( Score( 60 ) );
			std::cout << "h3 : " << h3.Get()->Value() << std::endl;
		}
		catch (const const char* c)
		{
			std::cout << "error : " << c << std::endl;
		}


	}
}