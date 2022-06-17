#pragma once

#include "Factory.h"
#include "ListLink.h"
#include "ListTray.h"
#include "ListPage.h"

namespace listfactory
{
	class ListFactory : public factory::Factory
	{
	public:
		factory::Link* createLink( string caption, string url ) override
		{
			return new ListLink( caption, url );
		}

		factory::Tray* createTray( string caption ) override
		{
			return new ListTray( caption );
		}

		factory::Page* createPage( string title, string author ) override
		{
			return new ListPage( title, author );
		}
	};
}