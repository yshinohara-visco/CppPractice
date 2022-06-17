#pragma once

#include <string>
using std::string;

namespace factory
{
	class Item
	{
	public:
		Item( string caption )
		{
			this->caption = caption;
		}

		virtual string makeHTML() = 0;

	protected:
		string caption;
	};
}