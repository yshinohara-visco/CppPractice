#pragma once

#include <variant>
#include <string>
#include <iostream>

/*
variantは継承関係にない複数の型を単一のオブジェクトに代入・切替ができる。
列挙した型を同一オブジェクトとして扱える点で多態性を表現している。
ビジター関数オブジェクトによって型ごとの動作を定義できる。

返り値を揃える必要がある。
継承関係にあるクラスを作って多態性を使ったらいいのでは？？？
*/
namespace Variant
{
	void Test1();


	/*
	成功時、失敗時で2種類の結果データを返す可能性がある関数を定義したとして、
	この場合も2つの親Resultとかを定義して継承させる方が絶対分かりやすい
	*/
	class ResultSuccess
	{
	public:
		void Print() { std::cout << "Result: Success" << std::endl; }
	};

	class ResultFailure
	{
	public:
		void Print() { std::cout << "Result: Failure" << std::endl; }
		void Why() { std::cout << "siran" << std::endl; }
	};

	std::variant<ResultSuccess, ResultFailure> GetResult( bool b );
	void Test2();
}