#pragma once

//オリジナルな例外クラス

#include <stdexcept>

class FileTreatmentException : public std::runtime_error
{
public:
    FileTreatmentException(const char* _Message, int info_hoge)
        :_AddErrorInfo_HOGE(info_hoge), runtime_error(_Message)
    {}

    //こんな風に追加の情報を載せることができるらしい
    int returnAddInfo()
    {
        return _AddErrorInfo_HOGE;
    }
private:
    int _AddErrorInfo_HOGE;
};