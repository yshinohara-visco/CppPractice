#include "Mini.h"
#include "Hide.h"
#include "TestZittaika.h"
#include "TestZWM.h"

#include <iostream>

int main()
{
	Mini::Test();
	//Hide::Test1();
	//Hide::Test2();
	//Zittaika::Test();
	ZittaikaWithMethod::Test();
}

/*
参考
https://qiita.com/kari_tech/items/42a5d342b6f4854a215f
https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp

2つ目のリンクのメソッド2，3について
使う側がcppをインクルードしたり、ヘッダがcppをインクルードしたりは、cppの変更が
各利用ファイルに影響してリビルドになるのでわける意味がないのでは？
*/