#pragma once

/*
ヘッダにはヘッダに必要な情報のみ書くようにしたい

このヘッダに他のヘッダ1のインクルードを書くと、このヘッダをインクルードするヘッダ2は
ヘッダ1もインクルードすることになる。これが数珠つなぎに繋がっていくと、ヘッダを1つ
編集しただけで他のヘッダも大量に変更扱いになってリビルドの量が大変なことになる場合がある。
これを避けるために、ヘッダにはなるべくインクルードを書きたくない。
その手段について

1．前方宣言を使う。
　メンバ変数がポインタである時、前方宣言を使える。
  cppでインクルードが必要なのでcppのインクルードは増える。
  ポインタでは無く実体のメンバ変数は初期化の為にヘッダの情報が必要になる。

2．スマートポインタにした上で前方宣言にする。
　ポインタではなく実体として所持したいクラスは、ユニークポインタにしてもほぼ同じように扱える。
  ユニークポインタにするとヘッダからcppにインクルードを移すことが出来る。

3．Pimplパターンを使う
　private変数、関数に限っては宣言と実装をcppに隠せるのでヘッダでインクルードする必要は無い。
  
*/

#include <memory>

//インクルードせずに前方宣言
class Hoge1;
class Hoge2;

namespace ReduceInclude
{
	class Printer
	{
	public:
		Printer();
		~Printer();

		void PrintHoge1();
		void PrintHoge2();
		void PrintHoge3();

		//関数の引数としてはポインタでなくても前方宣言でいいらしい
		void Print( Hoge1 hoge1 );
		void Print( Hoge2 hoge2 );
		//void Print( Hoge3 hoge3 );

	//確認用としてprivate変数とPimplを同居させている
	private:
		Hoge1* m_hoge1;
		std::unique_ptr<Hoge2> m_hoge2;

	private:
		class PrinterImpl* m;
	};


	void Test();
}