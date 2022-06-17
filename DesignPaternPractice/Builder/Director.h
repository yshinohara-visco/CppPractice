#pragma once

#include "Builder.h"

class Director
{
public:
	Director(Builder* builder)
	{
		this->builder = builder;
	}

	void construct()
	{
		builder->makeTitle("Greeting"); //�����\�z
		builder->makeString("�����璋�ɂ�����"); //�^�C�g��1
		builder->makeItems({ //�ӏ�����
			"���͂悤�������܂�",
			"����ɂ���"
			});
		builder->makeString("���"); //�^�C�g��2
		builder->makeItems({ //�ӏ�����
			"����΂��",
			"���₷�݂Ȃ���",
			"���悤�Ȃ�"
			});
		builder->close(); //����������
	}

private:
	Builder* builder;
};