#include "Zittaika.h"
#include <iostream>

// テンプレート関数、テンプレートクラスの定義
// ここで実体化した型しか使えない
// 2種類程度ならテンプレートを使わずオーバーロードをした方が分かりやすい

namespace Zittaika
{
	template <class T>
	void TemplateMethod( T t )
	{
		std::cout << "TemplateMethod : " << t << std::endl;
	}
	//明示的実体化
	template void TemplateMethod( int t );
	template void TemplateMethod( std::string t );
	//int と std::string のみ使用可になった

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

	//明示的実体化
	template class TemplateClass<double>;
	template class TemplateClass<std::string>;
	//doubleとstd::stringのみ使用可になった
}