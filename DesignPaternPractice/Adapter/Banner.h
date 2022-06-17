#pragma once

/*
Adaptee 適合される側

あらかじめ提供されているクラスとする
今回は保持した文字列を()か**で囲んで出力するやつ
*/

#include <string>
#include <iostream>

class Banner
{
public:
	Banner(std::string string)
	{
		this->string = string;
	}

	void showWithParen()
	{
		std::cout << "(" + string + ")" << std::endl;
	}

	void showWithAster()
	{
		std::cout << "*" << string << "*" << std::endl;
	}

private:
	std::string string;
};