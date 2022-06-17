#pragma once

/*
Target　対象

インタフェース
弱く出力、強く出力、の概念のみを定義
*/

class Print
{
public:
	virtual void PrintWeak() = 0;
	virtual void PrintStrong() = 0;
};