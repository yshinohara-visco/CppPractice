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

        //コマンド実行し結果を読みとる
        FILE* pfcmd = _popen( command.c_str(), "r" );
        if (!pfcmd)
            return exitcode;

        //結果を格納
        while (nullptr != fgets( buf.get(), size, pfcmd ))
        {
            output += buf.get();
        }
        //末尾の改行は削除
        if (0 < output.size())
            output.erase( output.end() - 1 );

        //パイプクローズ
        exitcode = _pclose( pfcmd );

        return exitcode;
    }
}