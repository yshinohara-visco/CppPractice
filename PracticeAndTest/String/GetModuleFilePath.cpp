#include "GetModuelFilePath.h"

#include "atlstr.h"
#include <iostream>
#include <fstream>

namespace GetPathTest
{
	void Test()
	{
		//���s�t�@�C���̃p�X���擾����
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
		
		//�p�X�̎w��ɋ�؂蕶�������������Ă��ǂ��̂��̊m�F
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
		ofs.open( out ); //test.text�̑O�ɋ�؂蕶����2�ł��邪���삵��
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