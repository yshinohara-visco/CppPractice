#pragma once

namespace Destructor
{
	class ParentA
	{
	public:
		ParentA();
		~ParentA();
	};

	class ParentB
	{
	public:
		ParentB();
		virtual ~ParentB();
	};

	class ChildA : public ParentA
	{
	public:
		ChildA();
		~ChildA();
	};

	class ChildB : public ParentB
	{
	public:
		ChildB();
		~ChildB();
	};

	void Test();

}