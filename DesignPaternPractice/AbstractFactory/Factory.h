#pragma once

#include "Link.h"
#include "Tray.h"
#include "Page.h"

namespace factory
{
	class Factory
	{
	public:
		//C++に文字列でクラスを指定してインスタンス作るなんてもんは無さそうなのでgetFactory()はあきらめる

		virtual Link* createLink( string caption, string url ) = 0;
		virtual Tray* createTray( string caption ) = 0;
		virtual Page* createPage( string title, string author ) = 0;
	};
}