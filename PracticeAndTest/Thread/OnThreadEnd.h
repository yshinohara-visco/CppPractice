#pragma once
#include <functional>
#include <string>
#include <vector>

namespace OnThreadEnd
{
	void Test();

	void Worker( std::vector<int> vecData, std::function<void( std::string )> onEnd );

	void OnEnd1( std::string str );
	void OnEnd2( std::string str );
}