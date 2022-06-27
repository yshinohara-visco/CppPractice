#include "Pimpl.h"
#include <functional>
#include <iostream>

namespace Pimpl
{
	class PrinterImpl
	{
	public:
		//privateメンバ関数の代わり
		std::function<void()> print;

		//privateメンバ変数の代わり
		std::string str;
	};

	//----------------------------------------------

	Printer::Printer( std::string str )
		:m( new PrinterImpl )
	{
		m->str = str;

		//privateメンバ関数ポジションの宣言、定義をcppに隠している
		m->print = [&]()
		{
			std::cout << "PrinterImpl : " << m->str << std::endl;
		};
	}

	Printer::~Printer()
	{
		delete m;
	}

	void Printer::Print()
	{
		m->print();
	}

	//-------------------------

	void Test()
	{
		Printer printer( "test" );
		printer.Print();
	}
}