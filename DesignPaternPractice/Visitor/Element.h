#pragma once
#include "Visitor.h"

class Element
{
public:
	void accept( Visitor v );
};