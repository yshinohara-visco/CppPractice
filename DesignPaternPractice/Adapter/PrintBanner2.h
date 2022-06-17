 #pragma once

/*
移譲を使ったパターン
こっちのが好み
*/

#include "Print.h"
#include "Banner.h"

class PrintBanner2 : public Print
{
public:
	PrintBanner2(std::string string)
	{
		banner = new Banner(string);
	}

	void PrintWeak() override
	{
		banner->showWithAster();
	}

	void PrintStrong() override
	{
		banner->showWithParen();
	}

private:
	Banner* banner;
};