#pragma once

/*
Adapter

Print‚Ì“ñ‚Â‚ÌŠÖ”‚Ì’†g‚ğBanner‚ğ—p‚¢‚ÄÀŒ»
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

