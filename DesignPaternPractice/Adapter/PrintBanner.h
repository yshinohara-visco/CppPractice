#pragma once

/*
Adapter

Printの二つの関数の中身をBannerを用いて実現
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

