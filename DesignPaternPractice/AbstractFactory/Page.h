#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include "Item.h"
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;

namespace factory
{
	class Page
	{
	public:
		Page( string title, string author )
		{
			this->title = title;
			this->author = author;
		}

		void add( Item* item )
		{
			content.push_back( item );
		}

		void output()
		{
			string filename = title + ".html";
			ofstream of( filename );
			if (of.is_open() == false)
			{
				cout << "can't open file" << endl;
				abort();
			}
			of << this->makeHTML();
			of.close();
			cout << filename + "を作成しました。" << endl;
		}

		virtual string makeHTML() = 0;

	protected:
		string title;
		string author;
		vector<Item*> content;
	};
}