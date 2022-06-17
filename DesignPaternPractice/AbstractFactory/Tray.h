#pragma once

#include <vector>
#include "Link.h"
using std::vector;

namespace factory
{
	class Tray : public Item
	{
	public:
		Tray( string caption )
			:Item( caption )
		{}

		void add( Item* item )
		{
			tray.push_back( item );
		}

		//makeHTMLが未実装なので抽象クラス

	protected:
		vector<Item*> tray;
	};
}