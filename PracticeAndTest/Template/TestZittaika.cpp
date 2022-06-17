#include "TestZittaika.h"
#include "Zittaika.h"
#include <string>

// テスト用の関数の定義
// この関数がZittaika.cppにあるとそれによって実体化が行われリンクが解決する

namespace Zittaika
{
	void Test()
	{
		TemplateMethod( 100 );
		//TemplateMethod( 10.0 ); 実体化していないので駄目
		TemplateMethod( std::string("method") );

		//TemplateClass<int> t0( 100 ); 実体化していないので駄目
		TemplateClass<double> t1( 100.0 );
		TemplateClass<std::string> t2( std::string("class") );

		t1.Print();
		t2.Print();
	}
}
