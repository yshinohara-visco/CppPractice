#include "FunctionTest.h"
#include <iostream>

namespace FunctionTest
{
	ValueHolder::ValueHolder()
		:m_value( 0 ) {}

	ValueHolder::ValueHolder( int value )
		: m_value( value ) {}

	int ValueHolder::GetValue()
	{
		return m_value;
	}

	void ValueHolder::Modify( std::function<void( int& )> func )
	{
		func( m_value );
	}

	/*
	 値を変更する処理そのものをそれぞれで作成し渡すことで関数を
	 増やしまくらずに済むか？と思ったが、どこでどう変更しているか
	 追いにくい点ではメンバ変数をpublicにしてしまうのと同レベルか？

	 widgetsのイベントを経由して遠い所の値を変えるところとかで何とか活かせないか？
	 functionを作るところとholderを持っているスコープが違う時とか。
	 */
	void Test1()
	{
		ValueHolder holder( 0 );

		auto print = [&]()
		{
			std::cout << "value is " << holder.GetValue() << std::endl;
		};

		print();

		holder.Modify( []( int& value )
			{
				value += 1;
			} );
		print();

		holder.Modify( []( int& value )
			{
				value += 10;
			} );
		print();

		holder.Modify( []( int& value )
			{
				value = std::pow( value, 2 );
			} );
		print();
	}
}