#pragma once
#include <string>
#include "Element.h"

class Entry : public Element
{
public:
	virtual std::string getName();
	virtual int getSize();
	//忘れた
};