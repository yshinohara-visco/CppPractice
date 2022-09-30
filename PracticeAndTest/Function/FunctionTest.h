#pragma once

#include <functional>

/*
応用が利きすぎて読みにくさの原因にもなっていそうなstd::function
可能性は感じるので良い感じの使い方を探りたい
*/

namespace FunctionTest
{
	//値の変更処理を外部から渡せるみたいな
	class ValueHolder
	{
	public:
		ValueHolder();
		ValueHolder( int value );

		int GetValue();
		void Modify( std::function<void( int& )> func );

	private:
		int m_value;
	};

	void Test1();
}
