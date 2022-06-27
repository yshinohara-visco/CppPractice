#pragma once
#include <string>

/*
Implクラスのみをプライベート変数として持つ
元々privateで宣言していた変数、関数をImplクラスにcppで宣言、定義する
ヘッダからprivateの情報を完全に隠すことができる
　+ pritvate部分の変更でヘッダを編集する必要が無くなる
  + private用のインクルードをヘッダでしなくて良くなる
  + ↑によってコンパイル時間の短縮を狙える
  - 書き方が面倒くさい
  - コンストラクタが長くなる
  - Implの削除を忘れずに行う必要がある
  - 読みにくい

個人的にはこのパターンに慣れていないと読むのも一苦労なので好きではない
がメリットが大きいのも確か
*/

namespace Pimpl
{
	class Printer
	{
	public:
		Printer( std::string str );
		~Printer();

		void Print();

	private:
		class PrinterImpl* m;
	};

	void Test();
}