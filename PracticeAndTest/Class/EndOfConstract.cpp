#include "EndOfConstract.h"

#include <iostream>

namespace EndOfConstract
{
	Base::Base()
	{
		Constract();
	}

	void Base::Print()
	{
		doPrint();
	}

	void Base::Constract()
	{
		std::cout << "Base::Constract()" << std::endl;
	}


	void Base::doPrint()
	{
		std::cout << "Base::doPrint()" << std::endl;
	}

	/*
	Baseのコンストラクタで呼ばれる関数はoverrideしているが、
	Baseの内容が実行される
	*/
	Impl::Impl()
		:Base()
	{
	}

	/*
	Base::Print()が実行するdoPrint()はオーバーライドされた内容になる。
	*/
	void Impl::BasePrint()
	{
		Base::Print();
	}

	void Impl::Constract()
	{
		std::cout << "Impl::Constract()" << std::endl;
	}

	void Impl::doPrint()
	{
		std::cout << "Impl::doPrint()" << std::endl;
	}

	void Test()
	{
		Base b;
		b.Print();

		std::cout << std::endl;

		Impl i;
		i.Print();
		i.BasePrint();
	}
	/*
	出力

	Base::Constract()
	Base::doPrint()

	Base::Constract()
	Impl::doPrint()
	Impl::doPrint()

	*/
};
