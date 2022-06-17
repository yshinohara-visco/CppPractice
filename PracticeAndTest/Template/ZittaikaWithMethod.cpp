#include "ZittaikaWithMethod.h"
#include <iostream>

// テンプレート関数、テンプレートクラスの定義
// ここで実体化した型しか使えない
// 2種類程度ならテンプレートを使わずオーバーロードをした方が分かりやすい

namespace ZittaikaWithMethod
{
	template <class T>
	void TemplateMethod( T t )
	{
		std::cout << "TemplateMethod : " << t << std::endl;
	}

	template <class T>
	TemplateClass<T>::TemplateClass( T t )
	{
		m_t = t;
	}

	template <class T>
	void TemplateClass<T>::Print()
	{
		std::cout << "TemplateClass::Print : " << m_t << std::endl;
	}
	
	//この関数で使用している範囲は実体化されるらしい
	//メソッドも使用する必要があるらしく明示的実体化より書くことが多い
	void Method()
	{
		TemplateMethod<int>( 100 );
		TemplateMethod<std::string>( "" );

		TemplateClass<int> t0(10);
		TemplateClass<double> t1(10.0);
		TemplateClass<std::string> t2("");

		//使用しないとPrint()は実体化されず使えない
		//t0.Print();
		t1.Print();
		t2.Print();
	}
}