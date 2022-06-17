#pragma once

#include "Item.h"

namespace factory
{
	class Link : public Item
	{
	public:
		Link( string caption, string url )
			:Item( caption )
		{
			this->url = url;
		}
		//makeHTMLが未実装なのでこれは抽象クラス

	protected:
		string url;
	};
}