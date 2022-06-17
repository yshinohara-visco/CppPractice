#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace Hide
{
	//テンプレートが関係ない処理の実装＋インタフェース
	class PrinterBase
	{
	public:
		PrinterBase() {}
		virtual void Print() = 0;

	protected:
		virtual void PrintFront();
		virtual void PrintBack();
	};

	template <class T>
	class PrinterImpl : public PrinterBase
	{
	public:
		PrinterImpl( T t )
		{
			m_t = t;
		}

		void Print()
		{
			PrintFront();
			std::cout << m_t;
			PrintBack();
		}

	private:
		T m_t;
	};

	//上の2つを使用すれば後から型が決まるような動作が出来る??
	//用途がある形ではないかも
	class PPrinter
	{
	public:
		PPrinter() {}

		template <class T>
		void SetValue( T value )
		{
			if (nullptr != m_pPrinter)
			{
				delete m_pPrinter;
			}

			m_pPrinter = new PrinterImpl<T>( value );
		}

		void Print();

	private:
		PrinterBase* m_pPrinter = nullptr;
	};

	void Test1();
	void Test2();
}