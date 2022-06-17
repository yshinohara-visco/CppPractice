#pragma once

#include "AbstractDisplay.h"
#include <iostream>

class CharDisplay : public AbstractDisplay
{
public:
	CharDisplay(char* ch)
	{
		this->ch = ch;
	}

	void open() override
	{
		std::cout << "<<";
	}

	void print() override
	{
		std::cout << ch;
	}

	void close() override
	{
		std::cout << ">>" << std::endl;
	}

private:
	char* ch;
};