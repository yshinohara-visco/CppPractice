#pragma once
#include <filesystem>

namespace CopyError
{
	void CopyFile1( int num, std::filesystem::path src, std::filesystem::path dst );
	void CopyFile2( int num, std::filesystem::path src, std::filesystem::path dst );
	void CopyFile3( int num, std::filesystem::path src, std::filesystem::path dst );
	void CopyFile4( int num, std::filesystem::path src, std::filesystem::path dst );
	void CopyFile5( int num, std::filesystem::path src, std::filesystem::path dst );

	void Test();
}

