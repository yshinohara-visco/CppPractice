#include "CalcPointer.h"
#include <iostream>

namespace CalcPointer
{
	//無効なポインタってなに？
	void Test1()
	{
		int i = 0;
		int* p = &i;
		int count = 0;

		//ある程度動いてしまうが最終的に例外になる
		//　→割り当てられたメモリ領域を超えた？
		while (true) //数百回で例外になった
		{
			std::cout << "p = " << p
				<< "  *p = " << *p
				<< "  count = " << count << std::endl;

			p++;
			count++;
		}

		//while (true) //26万回くらいで例外になった
		//{
		//	std::cout << "p = " << p
		//		<< "  *p = " << *p
		//		<< "  count = " << count << std::endl;

		//	p--;
		//	count++;
		//}
	}

	void Test2()
	{
		{
			int num[10];
			int* ptr = num;
			for (size_t i = 0; i < 10; i++)
			{
				*ptr = i;
				ptr++;
			}

			int* first = num;
			int* last = first + (10 - 1);
			auto lf = last - first; //ポインタの差はlong long らしい
			auto fl = first - last; //signedなので負の数も表せる

			std::cout << "first = " << first << " *first = " << *first << std::endl;
			std::cout << "last = " << last << " *last = " << *last << std::endl;
			std::cout << "last - first = " << lf << std::endl;
			std::cout << " first - last = " << fl << std::endl;
			/*
			出力
				first = 000000FBE87FF858 *first = 0
				last = 000000FBE87FF87C *last = 9
				last - first = 9
				 first - last = -9
			*/
		}

		std::cout << std::endl;
		{
			char num[10];
			char* ptr = num;
			for (size_t i = 0; i < 10; i++)
			{
				*ptr = i;
				ptr++;
			}

			char* first = num;
			char* last = first + (10 - 1);
			auto lf = last - first;
			auto fl = first - last;

			std::cout << "first = " << first << " *first = " << *first << std::endl;
			std::cout << "last = " << last << " *last = " << *last << std::endl;
			std::cout << "last - first = " << lf << std::endl;
			std::cout << " first - last = " << fl << std::endl;
			/*
			出力
				first =  *first =
				last =  ﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌﾌb・顯 *last =
				last - first = 9
				first - last = -9
			*/
		}

		std::cout << std::endl;
		{
			double num[10];
			double* ptr = num;
			for (size_t i = 0; i < 10; i++)
			{
				*ptr = i;
				ptr++;
			}

			double* first = num;
			double* last = first + (10 - 1);
			auto lf = last - first;
			auto fl = first - last;

			std::cout << "first = " << first << " *first = " << *first << std::endl;
			std::cout << "last = " << last << " *last = " << *last << std::endl;
			std::cout << "last - first = " << lf << std::endl;
			std::cout << " first - last = " << fl << std::endl;
			/*
			出力
				first = 000000FBE87FFA50 *first = 0
				last = 000000FBE87FFA98 *last = 9
				last - first = 9
				first - last = -9
			*/
		}

	}
}