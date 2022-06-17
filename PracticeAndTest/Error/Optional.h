#pragma once

#include <optional>
/*
optional クラス
1．オブジェクトの初期化タイミングを遅延させることが出来る
2．エラー報告のためにあらゆる方に共通の無効値表現を持たせる
*/

namespace  Optional
{
	//0割対策、その時の返り値はどうする？
	int Divide(int a, int b);

	//返り値に無効値を指定できる
	std::optional<int> SafeDivide( int a, int b);

	void Test();
}