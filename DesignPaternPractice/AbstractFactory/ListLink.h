#pragma once

#include "Link.h"

namespace listfactory
{
	class ListLink : public factory::Link
	{
	public:
		ListLink( string caption, string url )
			:Link( caption, url ) {};

		string makeHTML() override
		{
			return " <li><a href=\"" + url + "\">" + caption + "</a></li>\n";
		}
	};
}