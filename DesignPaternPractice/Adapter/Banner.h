#pragma once

/*
Adaptee �K������鑤

���炩���ߒ񋟂���Ă���N���X�Ƃ���
����͕ێ������������()��**�ň͂�ŏo�͂�����
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