#include "TestVariant.h"


namespace Variant
{
	struct Visitor
	{
		void operator()( int i )
		{
			std::cout << "int : " << i << std::endl;
		}
		void operator()( double d )
		{
			std::cout << "double : " << d << std::endl;
		}
		void operator()( std::string s )
		{
			std::cout << "string : " << s << std::endl;
		}
	};

	void Test1()
	{
		using hoge = std::variant<int, double, std::string>;
		hoge v1 = 1;
		hoge v2 = 1.1;
		hoge v3 = "hoge";

		std::visit( Visitor{}, v1 );
		std::visit( Visitor{}, v2 );
		std::visit( Visitor{}, v3 );
	}

	std::variant<ResultSuccess, ResultFailure> GetResult( bool b )
	{
		if (b)
		{
			return ResultSuccess();
		}
		else
		{
			return ResultFailure();
		}
	}

	void Test2()
	{
		auto a = GetResult( true );
		auto b = GetResult( false );

		std::visit( []( auto& result )
			{
				result.Print();
			}, a );
		if (a.index() == 1)
		{
			auto& f = std::get<ResultFailure>( a );
			f.Why();
		}


		std::visit( []( auto& result )
			{
				result.Print();
			}, b );
		if (b.index() == 1)
		{
			auto& f = std::get<ResultFailure>( b );
			f.Why();
		}
	}

}