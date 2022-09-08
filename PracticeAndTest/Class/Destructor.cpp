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
			std::cout << std::endl << "ParentA �ʏ�" << std::endl;
			ParentA a;
		}
		{
			std::cout << std::endl << "ParentA �|�C���^" << std::endl;
			ParentA* pa = new ParentA();
			delete pa;
		}
		{
			std::cout << std::endl << "ParentA ���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ParentA> ua = std::make_unique<ParentA>();
		}
		{
			std::cout << std::endl << "ParentA �V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ParentA> sa = std::make_shared<ParentA>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ParentB �ʏ�" << std::endl;
			ParentB b;
		}
		{
			std::cout << std::endl << "ParentB �|�C���^" << std::endl;
			ParentB* pb = new ParentB();
			delete pb;
		}
		{
			std::cout << std::endl << "ParentB ���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ParentB> ub = std::make_unique<ParentB>();
		}
		{
			std::cout << std::endl << "ParentB �V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ParentB> sb = std::make_shared<ParentB>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ChildA �ʏ�" << std::endl;
			ChildA a;
		}
		{
			std::cout << std::endl << "ChildA �|�C���^" << std::endl;
			ChildA* pa = new ChildA();
			delete pa;
		}
		{
			std::cout << std::endl << "ChildA �e�|�C���^" << std::endl;
			ParentA* pa = new ChildA();
			delete pa;
		}
		{
			std::cout << std::endl << "ChildA ���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ChildA> ua = std::make_unique<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA �e���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ParentA> ua = std::make_unique<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA �V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ChildA> ua = std::make_shared<ChildA>();
		}
		{
			std::cout << std::endl << "ChildA �e�V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ParentA> ua = std::make_shared<ChildA>();
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << std::endl << "ChildB �ʏ�" << std::endl;
			ChildB b;
		}
		{
			std::cout << std::endl << "ChildB �|�C���^" << std::endl;
			ChildB* pb = new ChildB();
			delete pb;
		}
		{
			std::cout << std::endl << "ChildB �e�|�C���^" << std::endl;
			ParentB* pb = new ChildB();
			delete pb;
		}
		{
			std::cout << std::endl << "ChildB ���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ChildB> ub = std::make_unique<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB �e���j�[�N�|�C���^" << std::endl;
			std::unique_ptr<ParentB> ub = std::make_unique<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB �V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ChildB> ub = std::make_shared<ChildB>();
		}
		{
			std::cout << std::endl << "ChildB �e�V�F�A�h�|�C���^" << std::endl;
			std::shared_ptr<ParentB> ub = std::make_shared<ChildB>();
		}

	}
}