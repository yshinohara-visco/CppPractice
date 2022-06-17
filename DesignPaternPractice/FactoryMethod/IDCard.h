#pragma once

/*
ConcreteProduct 具体的製品　肉付け
*/

#include <string>
#include <iostream>
#include "Product.h"

namespace idcard
{
	class IDCard :public framework::Product
	{
	public:
		IDCard( std::string owner )
		{
			std::cout << owner << "のカードを作ります。" << std::endl;
			this->owner = owner;
		}

		void use() override
		{
			std::cout << this->owner << "のカードを使います。" << std::endl;
		}

		std::string GetOwner()
		{
			return owner;
		}

	private:
		std::string owner;
	};
}