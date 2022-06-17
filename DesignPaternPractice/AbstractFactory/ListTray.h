#pragma once

#include "Tray.h"
#include <sstream>
using std::stringstream;
using std::endl;

namespace listfactory
{
	class ListTray : public factory::Tray
	{
	public:
		ListTray( string caption )
			:Tray( caption ) {};

		string makeHTML() override
		{
			stringstream buffer;
			buffer << "<li>" << endl;
			buffer << caption << endl;
			buffer << "<ul>";
			for (Item* item : tray)
			{
				buffer << item->makeHTML();
			}
			buffer << "</ul>" << endl;
			buffer << "</li>" << endl;

			return buffer.str();
		}
	};
}