#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include "Builder.h"
using std::stringstream;
using std::cout;
using std::endl;
using std::ofstream;

class HTMLBuilder : public Builder
{
public:
	void makeTitle(string title) override
	{
		filename = title + ".html"; //�t�@�C��������
		writer.open(filename); //�t�@�C���J��
		if (writer.is_open() == false)
		{
			cout << "can't open html file" << endl;
			abort();
		}

		writer << "<html><head><title>" + title + "</title></head><body>" << endl; //�^�C�g�����o��
		writer << "<h1>" + title + "</h1>" << endl;
	}

	void makeString(string str) override //HTML�t�@�C���ł̕�����
	{
		writer << "<p>" + str + "</p>" << endl;
	}

	void makeItems(vector<string> items) //HTML�t�@�C���ł̉ӏ�����
	{
		writer << "<ul>" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			writer << "<li>" + items.at(i) + "</li>" << endl;
		}
		writer << "</ul>" << endl;
	}

	void close() override //��������
	{
		writer << "</body></html>" << endl;
		writer.close();
	}

	string getRusult()
	{
		return filename;
	}

private:
	string filename;
	ofstream writer;
};