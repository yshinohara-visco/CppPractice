#include "Manager.h"
#include "MessageBox.h"
#include "UnderlinePen.h"

int main()
{
	//€”õ
	Manager* manager = new Manager();

	UnderlinePen* upen = new UnderlinePen("~");
	MessageBox* mbox = new MessageBox("*");
	MessageBox* sbox = new MessageBox("/");

	manager->registerProduct("strong message", upen);
	manager->registerProduct("warning box", mbox);
	manager->registerProduct("slash box", sbox);


	//¶¬
	Product* p1 = manager->create("strong message");
	p1->use("Hello world");
	Product* p2 = manager->create("warning box");
	p2->use("Hello world");
	Product* p3 = manager->create("slash box");
	p3->use("Hello world");

	return 0;
}