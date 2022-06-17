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
		builder->makeTitle("Greeting"); //文書構築
		builder->makeString("朝から昼にかけて"); //タイトル1
		builder->makeItems({ //箇条書き
			"おはようございます",
			"こんにちは"
			});
		builder->makeString("夜に"); //タイトル2
		builder->makeItems({ //箇条書き
			"こんばんは",
			"おやすみなさい",
			"さようなら"
			});
		builder->close(); //文書を完成
	}

private:
	Builder* builder;
};