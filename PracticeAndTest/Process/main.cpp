#include "CreateProcess.h"

#include <iostream>

int main()
{
	std::cout << "Run1 ---------------" << std::endl;
	int result1 = Process::Run1( "curl hoge" );
	std::cout << "exitcode = " << result1 << std::endl;

	std::cout << "Run2 ---------------" << std::endl;
	std::string output;
	int result2 = Process::Run2( "curl hoge", output );
	std::cout << "exitcode = " << result2 << std::endl;
	std::cout << "output = " << output << std::endl;


	std::cout << "---------------" << std::endl;
}