#pragma once

#include <memory>

namespace ReleaseTest
{
	class Checker
	{
	public:
		Checker();
		~Checker();

	private:
		int id = 0;
		static inline int num = 0;
	};
	using upChecker = std::unique_ptr<Checker>;
	#define makeUC std::make_unique<Checker>()

	void Test();
};