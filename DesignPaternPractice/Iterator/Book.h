#pragma once
#include <string>

class Book
{
public:
	Book(std::string name = "")
	{
		this->m_name = name;
	}

	std::string getName()
	{
		return m_name;
	}

private:
	std::string m_name;
};