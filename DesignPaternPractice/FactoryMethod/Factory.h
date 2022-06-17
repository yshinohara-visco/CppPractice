#pragma once

/*
Creator 工場のフレームワーク
*/

#include <string>
#include "Product.h"

namespace framework
{
	class Factory
	{
	public:
		Product* Create(std::string owner)
		{
			Product* p = createProduct(owner);
			registerProduct(p);
			return p;
		}

	protected:
		virtual Product* createProduct(std::string owner) = 0;
		virtual void registerProduct(Product* product) = 0;
	};
}