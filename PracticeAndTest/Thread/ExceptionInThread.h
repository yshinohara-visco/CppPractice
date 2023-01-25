#pragma once
#include <exception>
#include <string>

namespace ExceptionInThread
{
	class MyException : public std::exception
	{
	public:
		MyException( std::string message );
		std::string GetMessage() const;
	private:
		std::string m_msg;
	};

	void Test1();
	void Test2();
	void Test3();
	void Test4();
}