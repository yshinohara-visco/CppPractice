#include "GetModuelFilePath.h"

#include "atlstr.h"
#include <iostream>
#include <fstream>

namespace GetPathTest
{
	void Test()
	{
		//実行ファイルのパスを取得する
		CString path( "" );
		if (GetModuleFileName( NULL, path.GetBuffer( _MAX_PATH ), _MAX_PATH ))
		{
			TCHAR drive[_MAX_PATH];
			TCHAR dir[_MAX_PATH];
			TCHAR name[_MAX_PATH];
			TCHAR ext[_MAX_PATH];
			_tsplitpath_s( path, drive, dir, name, ext );
			path.Format( _T( "%s%s" ), drive, dir );

			std::wcout << (const wchar_t*)path << std::endl;
			std::wcout << drive << std::endl;
			std::wcout << dir << std::endl;
			std::wcout << name << std::endl;
			std::wcout << ext << std::endl;
		}
		
		//パスの指定に区切り文字が複数あっても良いのかの確認
		std::wofstream ofs;

		CString out( "" );
		out.Format( _T("%stest.txt"), (const wchar_t*)path );
		ofs.open( out );
		if (ofs.fail())
		{
			std::wcout << "fail : " << (const wchar_t*)out << std::endl;
		}
		else
		{
			std::wcout << "OK : " << (const wchar_t*)out << std::endl;
			ofs << "OK\n";
		}
		ofs.close();

		out.Format( _T( "%s\\test.txt" ), (const wchar_t*)path );
		ofs.open( out ); //test.textの前に区切り文字が2つできるが動作した
		if (ofs.fail())
		{
			std::wcout << "fail : " << (const wchar_t*)out << std::endl;
		}
		else
		{
			std::wcout << "OK : " << (const wchar_t*)out << std::endl;
			ofs << "OK\n";
		}
	}
}