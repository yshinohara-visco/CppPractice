#pragma once

#include <sstream>
#include "Builder.h"
using std::stringstream;
using std::endl;

class TextBuilder : public Builder
{
public:
	void makeTitle(string title) override
	{
		buffer << "==============================" << endl;
		buffer << "[" + title + "]" << endl;
		buffer << endl;
	}

	void makeString(string str) override
	{
		buffer << "@" + str << endl;
		buffer << endl;
	}

	void makeItems(vector<string> items) override
	{
		for (int i = 0; i < items.size(); i++)
		{
			buffer << "	*" + items.at(i) << endl;
		}
		buffer << endl;
	}

	void close() override
	{
		buffer << "==============================" << endl;
	}

	string getResult()
	{
		return buffer.str();
	}

private:
	stringstream buffer;
};