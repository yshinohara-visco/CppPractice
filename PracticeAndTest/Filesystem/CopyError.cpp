#include "CopyError.h"
#include <filesystem>
#include <iostream>
#include <functional>

namespace fs = std::filesystem;

namespace CopyError
{
	void CopyFile1( int num, std::filesystem::path src, std::filesystem::path dst )
	{
		std::cout << "Num." << num << "...";
		try
		{
			fs::copy_file( src, dst );
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cout << "errorcode:" << e.code() << "  what:" << e.what() << std::endl;
			return;
		}
		std::cout << "Success" << std::endl;
	}

	void CopyFile2( int num, std::filesystem::path src, std::filesystem::path dst )
	{
		std::cout << "Num." << num << "...";
		try
		{
			fs::copy_file( src, dst, fs::copy_options::overwrite_existing );
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cout << "errorcode:" << e.code() << "  what:" << e.what() << std::endl;
			return;
		}
		std::cout << "Success" << std::endl;
	}

	void CopyFile3( int num, std::filesystem::path src, std::filesystem::path dst )
	{
		std::cout << "Num." << num << "...";
		std::error_code ec;
		fs::copy_file( src, dst, ec );
		std::cout << "errorcode:" << ec << std::endl;
	}

	void CopyFile4( int num, std::filesystem::path src, std::filesystem::path dst )
	{
		std::cout << "Num." << num << "...";
		std::error_code ec;
		fs::copy_file( src, dst, fs::copy_options::overwrite_existing, ec );
		std::cout << "errorcode:" << ec << std::endl;
	}

	void CopyFile5( int num, std::filesystem::path src, std::filesystem::path dst )
	{
		std::cout << "Num." << num << "...";
		if (!fs::is_regular_file(src))
		{
			std::cout << "NotFound" << std::endl;
		}
		else if (fs::exists(dst) && !fs::is_regular_file(dst))
		{
			std::cout << "ExistUnregularFile" << std::endl;
		}
		else if (fs::exists(dst) && fs::equivalent(src, dst))
		{
			std::cout << "Equivalent" << std::endl;
		}
		else
		{
			std::error_code ec;
			fs::copy_file( src, dst, fs::copy_options::overwrite_existing, ec );
			std::cout << "errorcode:" << ec << std::endl;
		}
	}

	void Test()
	{
		fs::path src = "testfile.txt";
		fs::path dst = "dstpath.txt";
		fs::path dst2 = "dst2.txt";

		auto test = [&]( std::function<void( int, fs::path, fs::path )> copy )
		{
			//dst2(リンクを作成)
			fs::remove( dst2 );
			fs::create_hard_link( src, dst2 );

			//1.dstない
			fs::remove( dst );
			copy( 1, src, dst );

			//2.dstが既にある
			copy( 2, src, dst );

			//3.srcが無い
			copy( 3, "hoge", dst );

			//4.リンクにコピーしようとする
			copy( 4, src, dst2 );

			//5.自身にコピー
			copy( 5, src, src );
		};

		std::error_code ec;
		
		test( CopyFile1 );
		std::cout << std::endl;
		test( CopyFile2 );
		std::cout << std::endl;
		test( CopyFile3 );
		std::cout << std::endl;
		test( CopyFile4 );
		std::cout << std::endl;
		test( CopyFile5 );
	}
}