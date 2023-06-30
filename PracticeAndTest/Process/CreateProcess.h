#pragma once

#include <string>

namespace Process
{
	int Run1( std::string command );

	int Run2( std::string command, std::string& output );
}