
/*
Client�@�˗���
Target�̃��\�b�h���g���Ďd��������
*/

#include "PrintBanner.h"
#include "PrintBanner2.h"

int main()
{
	Print* p = new PrintBanner("Hello");
	p->PrintWeak();
	p->PrintStrong();

	std::cout << std::endl;

	Print* p2 = new PrintBanner2("HelloHello");
	p2->PrintWeak();
	p2->PrintStrong();

	return 0;
}