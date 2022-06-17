
#pragma once

#include <iostream>
#include "Product.h"

class UnderlinePen : public Product
{
public:
	UnderlinePen(std::string ulchar)
	{
		this->ulchar = ulchar;
	}

	void use(std::string s) override
	{
		int length = s.length();
		std::cout << "\\" + s + "\\" << std::endl;
		std::cout << " ";
		for (int i = 0; i < length; i++)
		{
			std::cout << ulchar;
		}
		std::cout << " " << std::endl;
	}

	Product* createClone() override
	{
		Product* p = new UnderlinePen(*this);//これでいいのかは知らん　ポインタとかあるとたぶんアウト
		return p;
	}

private:
	std::string ulchar;
};