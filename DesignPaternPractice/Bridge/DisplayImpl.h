#pragma once
//実装のクラスの最上位

class DisplayImpl
{
public:
    virtual void rawOpen() = 0;
    virtual void rawPrint() = 0;
    virtual void rawClose() = 0;
};