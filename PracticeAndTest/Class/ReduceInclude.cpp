#include "ReduceInclude.h"
#include "Hoge1.h"
#include "Hoge2.h"
#include "Hoge3.h"

#include <functional>

namespace ReduceInclude
{
	class PrinterImpl
	{
	public:
		Hoge3 hoge3;
	};

	//---------------------

	Printer::Printer()
		:m( new PrinterImpl )
	{
		m_hoge1 = new Hoge1();
		m_hoge2 = std::make_unique<Hoge2>( Hoge2() );
	}

	Printer::~Printer()
	{
		delete m_hoge1;
		// m_hoge2‚ÍŸŽè‚ÉÁ‚¦‚é
		delete m;
	}

	void Printer::PrintHoge1()
	{
		m_hoge1->Print();
	}

	void Printer::PrintHoge2()
	{
		m_hoge2->Print();
	}

	void Printer::PrintHoge3()
	{
		m->hoge3.Print();
	}

	void Printer::Print( Hoge1 hoge1 )
	{
		hoge1.Print();
	}

	void Printer::Print( Hoge2 hoge2 )
	{
		hoge2.Print();
	}

	Hoge1 Printer::CreateHoge1()
	{
		return Hoge1();
	}

	Hoge2 Printer::CreateHoge2()
	{
		return Hoge2();
	}


	//void Printer::Print( Hoge3 hoge3 )
	//{
	//	hoge3.Print();
	//}

	//------------------------

	void Test()
	{
		Printer printer;
		printer.PrintHoge1();
		printer.PrintHoge2();
		printer.PrintHoge3();

		Hoge1 hoge1 = printer.CreateHoge1();
		Hoge2 hoge2 = printer.CreateHoge2();
		printer.Print( hoge1 );
		printer.Print( hoge2 );
	}
}