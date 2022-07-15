#pragma once

#include <vector>
#include <memory>
#include <iostream>

namespace ReturnUnique
{
	/*
	メモリを多く確保するクラスがあったとして、それの作成する関数を作りたい。
	普通に返すとコピーしてしまうのが嫌。
	newしてポインタを返すとdelete忘れが怖い。
	unique_ptrなら関数内で作成したインスタンスを所有権渡すことで、
	コピー無しで消し忘れの心配もない。らしい。
	*/

	class BigData
	{
	public:
		BigData();

		//コピーコンストラクタ
		BigData( const BigData& d );

		//デストラクタ
		~BigData();

	private:
		char* ptr;
	};

	BigData MakeData();
	BigData* MakeDataP();
	std::unique_ptr<BigData> MakeDataU();

	void Test();
};

