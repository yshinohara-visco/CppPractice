#include "IDCardFactory.h"

//using namespace framework;
//using namespace idcard;

int main()
{
	framework::Factory* factory = new idcard::IDCardFactory();
	
	framework::Product* card1 = factory->Create("山田太郎");
	framework::Product* card2 = factory->Create("山田花子");
	framework::Product* card3 = factory->Create("山田太一郎");

	card1->use();
	card2->use();
	card3->use();

	return 0;
}