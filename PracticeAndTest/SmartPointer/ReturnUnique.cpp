#include "ReturnUnique.h"
#include <iostream>

namespace ReturnUnique
{
	BigData::BigData()
	{
		std::cout << "コンストラクタ" << std::endl;
		ptr = new char[1000];
	}

	//コピーコンストラクタ
	BigData::BigData( const BigData& d )
	{
		std::cout << "コピーコンストラクタ" << std::endl;
		ptr = new char[1000];
		std::copy( d.ptr, d.ptr + 1000, ptr ); //時間がかかるらしい？？
	}

	//デストラクタ
	BigData::~BigData()
	{
		delete[] ptr;
	}


	BigData MakeData()
	{
		BigData data; //ローカルでインスタンスを作成
		return data; //そのコピーを返す
	}

	BigData* MakeDataP()
	{
		BigData* pData = new BigData(); //ヒープにインスタンスを作成
		return pData; //そのアドレスを返す
	}

	std::unique_ptr<BigData> MakeDataU()
	{
		//make_uniqueを使うとコピーコンストラクタが動いていた なんだその裏切りは
		//auto upData = std::make_unique<BigData>( BigData() );

		auto upData = std::unique_ptr<BigData>( new BigData() );
		return upData; //右辺値がどうのでunique_ptrをそのまま返すことができる
	}

	void Test()
	{
		std::cout << "コピーを返す場合" << std::endl;
		BigData data = MakeData();

		std::cout << std::endl << "ポインタを返す場合" << std::endl;
		BigData* p = MakeDataP();
		delete p; //deleteを忘れるとメモリリークする　危険

		std::cout << std::endl << "ユニークポインタを返す場合" << std::endl;
		auto up = MakeDataU();

	}
}