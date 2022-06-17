#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;


class Builder
{
public:
	virtual void makeTitle(string title) = 0;
	virtual void makeString(string str) = 0;
	virtual void makeItems(vector<string> items) = 0;
	virtual void close() = 0;
};