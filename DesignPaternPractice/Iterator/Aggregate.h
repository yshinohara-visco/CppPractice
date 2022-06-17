#pragma once
#include "Iterator.h"

class Aggregate
{
public:
	virtual Iterator* iterator() = 0;
};