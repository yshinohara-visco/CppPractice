#pragma once

// テンプレートメソッド、テンプレートクラスの宣言のみを行う

namespace ZittaikaWithMethod
{
	template <class T>
	void TemplateMethod( T t );

	template <class T>
	class TemplateClass
	{
	public:
		TemplateClass( T t );
		void Print();

	private:
		T m_t;
	};
}