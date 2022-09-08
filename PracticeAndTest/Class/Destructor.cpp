#include "Destructor.h"

#include <iostream>
#include <memory>

#define Print() std::cout << __FUNCTION__ << std::endl;

namespace Destructor
{
	ParentA::ParentA() { Print(); }
	ParentA::~ParentA() { Print(); }
	ParentB::ParentB() { Print(); }
	ParentB::~ParentB() { Print(); }
	ChildA::ChildA() { Print(); }
	ChildA::~ChildA() { Print(); }
	ChildB::ChildB() { Print(); }
	ChildB::~ChildB() { Print(); }

	void Test()
	{
		{
			std::cout << std::endl << "ParentA 通常" << std::endl;
			ParentA a;
		}
		{
			std::cout << std::endl << "ParentA ポインタ" << std::endl;
			ParentA* pa = new ParentA();
			delete pa;
		}
		{
			std::cout << std::endl << "ParentA ユニークポインタ" << std::endl;
			std::unique_ptr<ParentA> ua = std::make_unique<ParentA>();
		}
		{
			std::cout << std::endl << "ParentA シェアドポインタ" << std::endl;
			std::shared_ptr<ParentA> sa = std::make_shared<ParentA>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ParentB 通常" << std::endl;
			ParentB b;
		}
		{
			std::cout << std::endl << "ParentB ポインタ" << std::endl;
			ParentB* pb = new ParentB();
			delete pb;
		}
		{
			std::cout << std::endl << "ParentB ユニークポインタ" << std::endl;
			std::unique_ptr<ParentB> ub = std::make_unique<ParentB>();
		}
		{
			std::cout << std::endl << "ParentB シェアドポインタ" << std::endl;
			std::shared_ptr<ParentB> sb = std::make_shared<ParentB>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ChildA 通常" << std::endl;
			ChildA a;
		}
		{
			std::cout << std::endl << "ChildA ポインタ" << std::endl;
			ChildA* pa = new ChildA();
			delete pa;
		}
		{
			std::cout << std::endl << "ChildA 親ポインタ" << std::endl;
			ParentA* pa = new ChildA();
			delete pa;
		}
		{
			std::cout << std::endl << "ChildA ユニークポインタ" << std::endl;
			std::unique_ptr<ChildA> ua = std::make_unique<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA 親ユニークポインタ" << std::endl;
			std::unique_ptr<ParentA> ua = std::make_unique<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA シェアドポインタ" << std::endl;
			std::shared_ptr<ChildA> ua = std::make_shared<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA 親シェアドポインタ" << std::endl;
			std::shared_ptr<ParentA> ua = std::make_shared<ChildA>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ChildB 通常" << std::endl;
			ChildB b;
		}
		{
			std::cout << std::endl << "ChildB ポインタ" << std::endl;
			ChildB* pb = new ChildB();
			delete pb;
		}
		{
			std::cout << std::endl << "ChildB 親ポインタ" << std::endl;
			ParentB* pb = new ChildB();
			delete pb;
		}
		{
			std::cout << std::endl << "ChildB ユニークポインタ" << std::endl;
			std::unique_ptr<ChildB> ub = std::make_unique<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB 親ユニークポインタ" << std::endl;
			std::unique_ptr<ParentB> ub = std::make_unique<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB シェアドポインタ" << std::endl;
			std::shared_ptr<ChildB> ub = std::make_shared<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB 親シェアドポインタ" << std::endl;
			std::shared_ptr<ParentB> ub = std::make_shared<ChildB>();
		}

	}
}