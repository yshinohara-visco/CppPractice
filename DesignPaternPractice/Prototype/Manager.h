#pragma once

#include <map>
#include <string>
#include "Product.h"

class Manager
{
public:
	void registerProduct(std::string name, Product* proto)
	{
		showcase.emplace(name, proto);
	}

	Product* create(std::string protoname)
	{
		Product* p = showcase.at(protoname);
		return p->createClone();
	}

private:
	std::map<std::string, Product*> showcase;
};