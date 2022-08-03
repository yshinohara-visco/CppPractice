#pragma once


namespace EndOfConstract
{
	class Base
	{
	public:
		Base();

		void Print();

	private:
		virtual void Constract();

		virtual void doPrint();
	};

	class Impl : public Base
	{
	public:
		Impl();

		void BasePrint();

	private:
		void Constract() override;

		void doPrint() override;
	};

	void Test();
};

