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
	Base�̃R���X�g���N�^�ŌĂ΂��֐���override���Ă��邪�A
	Base�̓��e�����s�����
	*/
	Impl::Impl()
		:Base()
	{
	}

	/*
	Base::Print()�����s����doPrint()�̓I�[�o�[���C�h���ꂽ���e�ɂȂ�B
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
	�o��

	Base::Constract()
	Base::doPrint()

	Base::Constract()
	Impl::doPrint()
	Impl::doPrint()

	*/
};
