#include "FunctinoArgument.h"

#include <iostream>

namespace FunctionArgument
{
	void FunctionHolder::Set( std::function<void()> function )
	{
		m_func = function;
	}

	void FunctionHolder::Run()
	{
		if (m_func)
			m_func();
	}

	void PrintHoge()
	{
		std::cout << "Hoge" << std::endl;
	}

	Printer::Printer( std::string str )
	{
		m_str = str;
	}

	void Printer::SetStr( std::string str )
	{
		m_str = str;
	}

	void Printer::Print() const
	{
		std::cout << m_str << std::endl;
	}

	void Test()
	{
		auto func = [&]()
		{
			std::cout << "function" << std::endl;
		};

		FunctionHolder holder1, holder2, holder3, holder4, holder5, holder6;
		Printer printer( "Printer" );

		//�����_���ō����function���w��
		holder1.Set( func );
		//�֐����w��
		holder2.Set( PrintHoge );
		//�����o�֐��ƃC���X�^���X�̃R�s�[
		holder3.Set( std::bind( &Printer::Print, printer ) );
		//�����o�֐��ƃC���X�^���X�̎Q��
		holder4.Set( std::bind( &Printer::Print, &printer ) );
		//�����o�֐������s���郉���_��(�Q�ƃL���v�`��)
		holder5.Set( [&]() {printer.Print(); } );
		//�����o�֐������s���郉���_��(�R�s�[�L���v�`��)
		holder6.Set( [=]() {printer.Print(); } );

		holder1.Run();
		holder2.Run();
		holder3.Run();
		holder4.Run();
		holder5.Run();
		holder6.Run();
		std::cout << std::endl;

		printer.SetStr( "Printerrrrrrrrrrrr" );
		holder3.Run();
		holder4.Run();
		holder5.Run();
		holder6.Run();
	}
}
