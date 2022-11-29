#pragma once

#include <functional>
#include <string>

/*
コールバックとかで処理をfunctionの形で渡して渡した先で実行したりする
渡す形としては普通の関数、ラムダ式のほかにメンバ関数も渡せるらしい。
メンバ関数を実行するラムダ式を渡す方が分かりやすいかもしれない。
*/
namespace FunctionArgument
{
	class FunctionHolder
	{
	public:
		void Set( std::function<void()> function );
		void Run();

	private:
		std::function<void()> m_func;
	};

	void PrintHoge();

	class Printer
	{
	public:
		Printer( std::string str );
		void SetStr( std::string str );
		void Print() const;

	private:
		std::string m_str;
	};


	void Test();
}