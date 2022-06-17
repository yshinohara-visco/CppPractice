#pragma once

#include <iostream>
#include "Product.h"

class MessageBox : public Product
{
public:
	MessageBox(std::string decochar)
	{
		this->decochar = decochar;
	}

	void use(std::string s)
	{
		int length = s.length();
		for (int i = 0; i < length + 4; i++)
		{
			std::cout << decochar;
		}
		std::cout << std::endl;
		std::cout << decochar + " " + s + " " + decochar << std::endl;
		for (int i = 0; i < length + 4; i++)
		{
			std::cout << decochar;
		}
		std::cout << std::endl;
	}

	Product* createClone() override
	{
		Product* p = new MessageBox(*this);//‚±‚ê‚Å‚ ‚Á‚Ä‚é‚©‚í‚©‚ç‚ñ
		return p;
	}

private:
	std::string decochar;
};