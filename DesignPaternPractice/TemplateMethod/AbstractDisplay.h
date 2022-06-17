#pragma once

class AbstractDisplay
{
public:

	virtual void open() = 0;
	virtual void print() = 0;
	virtual void close() = 0;
	void display()
	{
		open();
		for (int  i = 0; i < 5; i++)
		{
			print();
		}
		close();
	}
};