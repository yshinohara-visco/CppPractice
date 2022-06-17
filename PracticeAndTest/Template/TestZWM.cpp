#include "TestZWM.h"
#include "ZittaikaWithMethod.h"
#include <string>

namespace ZittaikaWithMethod
{
	void Test()
	{
		TemplateMethod( 100 );
		//TemplateMethod( 10.0 ); 実体化していないので駄目
		TemplateMethod( std::string( "method" ) );

		TemplateClass<int> t0( 1 );
		TemplateClass<double> t1( 100.0 );
		TemplateClass<std::string> t2( std::string( "class" ) );

		//t0.Print(); TempalteClass<int>::Print()は実体化されておらず使えない
		t1.Print();
		t2.Print();
	}
}