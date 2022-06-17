#include "Optional.h"

#include<iostream>

namespace Optional
{
	int Divide( int a, int b )
	{
		//0割対策をどうする？
		if (0 == b)
		{
			return 0; //返り値0が計算結果か、0割なのかが分からない
		}
		return a / b;
	}

	std::optional<int> SafeDivide( int a, int b )
	{
		if (0 == b)
		{
			return std::nullopt; //明確な無効値を返すことができる
		}
		return a / b;
	}

	void Test()
	{
		std::cout << "Divide(20, 4) : " << Divide( 20, 4 ) << std::endl;
		std::cout << "Divide(0, 4) : " << Divide( 0, 4 ) << std::endl;
		std::cout << "Divide(20, 0) : " << Divide( 20, 0 ) << std::endl; //0割

		auto safeDivide = [&](int a, int b)
		{
			std::cout << "SafeDivide(" << a << ", " << b << ") : ";
			std::optional<int> result;
			result = SafeDivide( a, b );
			if (result)
			{
				std::cout << result.value() << std::endl;
			}
			else
			{
				std::cout << "0割です" << std::endl;
			}
		};
		safeDivide( 20, 4 );
		safeDivide( 0, 4 );
		safeDivide( 20, 0 ); //0割
	}
}