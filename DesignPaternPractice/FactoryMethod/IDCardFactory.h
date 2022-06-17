#pragma once

/*
ConcreteCreater 具体的作成者　肉付け
*/

#include <vector>
#include "IDCard.h"
#include "Factory.h"

namespace idcard
{
	using framework::Product;
	using framework::Factory;

	class IDCardFactory : public Factory
	{
	public:
		std::vector<std::string> getOwners()
		{
			return owners;
		}

	protected:
		Product* createProduct( std::string owner ) override
		{
			return new IDCard( owner );
		}

		void registerProduct( Product* product )override
		{
			owners.push_back( ((IDCard*)product)->GetOwner() );
		}

	private:
		std::vector<std::string> owners;
	};
}