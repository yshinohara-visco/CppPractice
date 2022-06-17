#pragma once

#include <iostream>

namespace Mini
{
	template <class T>
	class Printer
	{
	public:
		Printer( T t )
		{
			m_t = t;
		}

		void Print()
		{
			std::cout << "Print : " << m_t << std::endl;
		}

	private:
		T m_t;
	};

	inline void Test()
	{
		std::string str( "hoge" );
		int i = 10;
		unsigned int u = 9;
		double d = 11;

		Printer<std::string> p0( str );
		Printer<int> p1( i );
		Printer<unsigned int> p2( u );
		Printer<double> p3( d );

		p0.Print();
		p1.Print();
		p2.Print();
		p3.Print();
	}
}

