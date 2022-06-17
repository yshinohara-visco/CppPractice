#include "Hide.h"

namespace Hide
{
	//テンプレートが関係ない処理
	void PrinterBase::PrintFront()
	{
		std::cout << "---[ ";
	}
	void PrinterBase::PrintBack()
	{
		std::cout << " ]---" << std::endl;
	}

	//Baseのインタフェースを使う都合上テンプレートの値の授受はできない→役に立たない？
	void PPrinter::Print()
	{
		m_pPrinter->Print();
	}

	//テスト
	void Test1()
	{
		std::string str( "hoge" );
		int i = 10;
		unsigned int u = 9;
		double d = 11;

		std::vector<PrinterBase*> vecPrinterPtr;
		vecPrinterPtr.push_back( new PrinterImpl<std::string>( str ) );
		vecPrinterPtr.push_back( new PrinterImpl<int>( i ) );
		vecPrinterPtr.push_back( new PrinterImpl<unsigned int>( u ) );
		vecPrinterPtr.push_back( new PrinterImpl<double>( d ) );
		;
		for (auto& ptr : vecPrinterPtr)
		{
			ptr->Print();
			delete ptr;
		}
		vecPrinterPtr.clear();
	}

	void Test2()
	{
		std::string str( "hoge" );
		int i = 10;
		unsigned int u = 9;
		double d = 11;

		PPrinter pp;
		pp.SetValue( str );
		pp.Print();
		pp.SetValue( i );
		pp.Print();
		pp.SetValue( u );
		pp.Print();
		pp.SetValue( d );
		pp.Print();
	}
}