#include "Pimpl.h"
#include <functional>
#include <iostream>

namespace Pimpl
{
	class PrinterImpl
	{
	public:
		//private�����o�֐��̑���
		std::function<void()> print;

		//private�����o�ϐ��̑���
		std::string str;
	};

	//----------------------------------------------

	Printer::Printer( std::string str )
		:m( new PrinterImpl )
	{
		m->str = str;

		//private�����o�֐��|�W�V�����̐錾�A��`��cpp�ɉB���Ă���
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