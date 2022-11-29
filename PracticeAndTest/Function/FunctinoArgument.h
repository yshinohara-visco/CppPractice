#pragma once

#include <functional>
#include <string>

/*
�R�[���o�b�N�Ƃ��ŏ�����function�̌`�œn���ēn������Ŏ��s�����肷��
�n���`�Ƃ��Ă͕��ʂ̊֐��A�����_���̂ق��Ƀ����o�֐����n����炵���B
�����o�֐������s���郉���_����n������������₷����������Ȃ��B
*/
namespace FunctionArgument
{
	class FunctionHolder
	{
	public:
		void Set( std::function<void()> function );
		void Run();

	private:
		std::function<void()> m_func;
	};

	void PrintHoge();

	class Printer
	{
	public:
		Printer( std::string str );
		void SetStr( std::string str );
		void Print() const;

	private:
		std::string m_str;
	};


	void Test();
}