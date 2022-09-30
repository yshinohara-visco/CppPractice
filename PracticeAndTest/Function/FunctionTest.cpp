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
	 �l��ύX���鏈�����̂��̂����ꂼ��ō쐬���n�����ƂŊ֐���
	 ���₵�܂��炸�ɍςނ��H�Ǝv�������A�ǂ��łǂ��ύX���Ă��邩
	 �ǂ��ɂ����_�ł̓����o�ϐ���public�ɂ��Ă��܂��̂Ɠ����x�����H

	 widgets�̃C�x���g���o�R���ĉ������̒l��ς���Ƃ���Ƃ��ŉ��Ƃ��������Ȃ����H
	 function�����Ƃ����holder�������Ă���X�R�[�v���Ⴄ���Ƃ��B
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