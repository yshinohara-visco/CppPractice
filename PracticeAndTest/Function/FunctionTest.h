#pragma once

#include <functional>

/*
���p�����������ēǂ݂ɂ����̌����ɂ��Ȃ��Ă�������std::function
�\���͊�����̂ŗǂ������̎g������T�肽��
*/

namespace FunctionTest
{
	//�l�̕ύX�������O������n����݂�����
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
