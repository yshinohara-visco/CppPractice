#include "CreateProcess.h"

#include <iostream>
#include <string>
#include <Windows.h>

namespace Process
{
    int Run1( std::string command )
    {
        return std::system( command.c_str() );
    }

    int Run2( std::string command, std::string& output )
    {
        const size_t size = 1024;
        auto buf = std::make_unique<char[]>( size );
        int exitcode = -1;

        //�R�}���h���s�����ʂ�ǂ݂Ƃ�
        FILE* pfcmd = _popen( command.c_str(), "r" );
        if (!pfcmd)
            return exitcode;

        //���ʂ��i�[
        while (nullptr != fgets( buf.get(), size, pfcmd ))
        {
            output += buf.get();
        }
        //�����̉��s�͍폜
        if (0 < output.size())
            output.erase( output.end() - 1 );

        //�p�C�v�N���[�Y
        exitcode = _pclose( pfcmd );

        return exitcode;
    }
}