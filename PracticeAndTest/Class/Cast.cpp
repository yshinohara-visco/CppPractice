#include "Cast.h"
#include <iostream>

namespace Cast
{
	void Test()
	{
		int i = 123;
		double d = 10.1;

		Holder holder;

		//int��ݒ肵int�Ƃ��ēǂ݂�����OK
		holder.Set( i );
		std::cout << "1 " << holder.Get<int>() << std::endl;

		//double��ݒ肵double�Ƃ��ēǂ݂�����OK
		holder.Set( d );
		std::cout << "2 " << holder.Get<double>() << std::endl;

		//int��ݒ肵double�Ƃ��ēǂ݂������K���Ȓl���o�͂���邪�����Ȃ�
		holder.Set( i );
		std::cout << "3 " << holder.Get<double>() << std::endl;

		//double��ݒ肵int�Ƃ��ēǂ݂������K���Ȓl���o�͂���邪�����Ȃ�
		holder.Set( d );
		std::cout << "4 " << holder.Get<int>() << std::endl;

		//�ϐ��̎��̈ʒu��double�Ƃ��Đݒ�A�ǂ݂������K���Ȓl���o�͂���邪�����Ȃ�
		double* hannigai = &d + 1;
		holder.Set( *hannigai );
		std::cout << "5 " << holder.Get<double>() << std::endl;

		double* nullpo = nullptr;
		//holder.Set( *nullpo ); null�Q�Ƃŗ�O�ɂȂ�

		Holder h2;
		//h2 = holder; unique_ptr�Ȃ̂ŃR�s�[�ł��Ȃ�
		h2 = std::move( holder );

		//����
		std::cout << "6 " << h2.Get<double>() << std::endl;
		//Get()�̎��s�͂ł��� ���g��null
		std::cout << "7 " << holder.Get<double>() << std::endl;

		{
			double* pDouble = reinterpret_cast<double*>(&i); //��O�o�Ȃ�
			std::cout << *pDouble << std::endl; //��O�o�Ȃ�

			int* pInt = reinterpret_cast<int*>(&d); //��O�o�Ȃ�
			std::cout << *pInt << std::endl; //��O�o�Ȃ�

			int* nulll = reinterpret_cast<int*>(nullpo); //��O�o�Ȃ�
			//std::cout << *nulll << std::endl; �����ŗ�O

			pInt = new int( 10 );
			delete pInt;
			double* del = reinterpret_cast<double*>(pInt); //��O�o�Ȃ�
			//std::cout << *del << std::endl; �����ŗ�O
		}
	}
}