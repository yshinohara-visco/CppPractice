#pragma once

#include <string>
#include <iostream>
#include "AbstractDisplay.h"

class StringDisplay : public AbstractDisplay
{
public:
	StringDisplay(std::string string)
	{
		this->string = string;
		this->width = string.length();
	}

	void open() override
	{
		PrintLine();
	}

	void print() override
	{
		std::cout << "|" << string << "|" << std::endl;
	}

	void close() override
	{
		PrintLine();
	}

private:
	std::string string;
	int width;

	void PrintLine() {
		std::cout << "+";
		for (int i = 0; i < width; i++)
		{
			std::cout << "-";
		}
		std::cout << "+" << std::endl;
	}
};