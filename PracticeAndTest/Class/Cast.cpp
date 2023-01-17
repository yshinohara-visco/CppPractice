#include "Cast.h"
#include <iostream>

namespace Cast
{
	void Test()
	{
		int i = 123;
		double d = 10.1;

		Holder holder;

		//intを設定しintとして読みだす→OK
		holder.Set( i );
		std::cout << "1 " << holder.Get<int>() << std::endl;

		//doubleを設定しdoubleとして読みだす→OK
		holder.Set( d );
		std::cout << "2 " << holder.Get<double>() << std::endl;

		//intを設定しdoubleとして読みだす→適当な値が出力されるが落ちない
		holder.Set( i );
		std::cout << "3 " << holder.Get<double>() << std::endl;

		//doubleを設定しintとして読みだす→適当な値が出力されるが落ちない
		holder.Set( d );
		std::cout << "4 " << holder.Get<int>() << std::endl;

		//変数の次の位置をdoubleとして設定、読みだす→適当な値が出力されるが落ちない
		double* hannigai = &d + 1;
		holder.Set( *hannigai );
		std::cout << "5 " << holder.Get<double>() << std::endl;

		double* nullpo = nullptr;
		//holder.Set( *nullpo ); null参照で例外になる

		Holder h2;
		//h2 = holder; unique_ptrなのでコピーできない
		h2 = std::move( holder );

		//動く
		std::cout << "6 " << h2.Get<double>() << std::endl;
		//Get()の実行はできる 中身はnull
		std::cout << "7 " << holder.Get<double>() << std::endl;

		{
			double* pDouble = reinterpret_cast<double*>(&i); //例外出ない
			std::cout << *pDouble << std::endl; //例外出ない

			int* pInt = reinterpret_cast<int*>(&d); //例外出ない
			std::cout << *pInt << std::endl; //例外出ない

			int* nulll = reinterpret_cast<int*>(nullpo); //例外出ない
			//std::cout << *nulll << std::endl; ここで例外

			pInt = new int( 10 );
			delete pInt;
			double* del = reinterpret_cast<double*>(pInt); //例外出ない
			//std::cout << *del << std::endl; ここで例外
		}
	}
}