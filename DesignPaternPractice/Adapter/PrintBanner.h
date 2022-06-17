#pragma once

/*
Adapter

Print�̓�̊֐��̒��g��Banner��p���Ď���
*/

#include "Banner.h"
#include "Print.h"

class PrintBanner : public Banner, public Print
{
public:
	PrintBanner(std::string string)
		:Banner(string)
	{
	}

	void PrintWeak() override
	{
		showWithParen();
	}

	void PrintStrong() override
	{
		showWithAster();
	}
};

