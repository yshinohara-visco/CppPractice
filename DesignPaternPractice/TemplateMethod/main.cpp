#include "CharDisplay.h"
#include "StringDisplay.h"

int main()
{
	char c[] = "Ha";
	AbstractDisplay* d1 = new CharDisplay(c);

	AbstractDisplay* d2 = new StringDisplay("Hello world");

	AbstractDisplay* d3 = new StringDisplay("‚±‚ñ‚É‚¿‚Í");

	d1->display();

	d2->display();
	d3->display();

	return 0;
}