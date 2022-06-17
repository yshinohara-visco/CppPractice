#pragma once

#include "Page.h"
#include <sstream>
using std::stringstream;
using std::endl;

namespace listfactory
{
	class ListPage : public factory::Page
	{
	public:
		ListPage( string title, string author )
			:Page( title, author ) {}

		string makeHTML() override
		{
			stringstream buffer;

			buffer << "<html><head><title>" + title + "</title></head>" << endl;
			buffer << "<body>" << endl;
			buffer << "<h1>" + title + "</h1>" << endl;
			buffer << "<ul>" << endl;
			for (factory::Item* item : content)
			{
				buffer << item->makeHTML();
			}
			buffer << "</ul>" << endl;
			buffer << "<hr><address>" + author + "</address>";
			buffer << "</body></html>" << endl;
			return buffer.str();

		}
	};
}