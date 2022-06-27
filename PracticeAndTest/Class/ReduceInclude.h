#pragma once

/*
�w�b�_�ɂ̓w�b�_�ɕK�v�ȏ��̂ݏ����悤�ɂ�����

���̃w�b�_�ɑ��̃w�b�_1�̃C���N���[�h�������ƁA���̃w�b�_���C���N���[�h����w�b�_2��
�w�b�_1���C���N���[�h���邱�ƂɂȂ�B���ꂪ����Ȃ��Ɍq�����Ă����ƁA�w�b�_��1��
�ҏW���������ő��̃w�b�_����ʂɕύX�����ɂȂ��ă��r���h�̗ʂ���ςȂ��ƂɂȂ�ꍇ������B
���������邽�߂ɁA�w�b�_�ɂ͂Ȃ�ׂ��C���N���[�h�����������Ȃ��B
���̎�i�ɂ���

1�D�O���錾���g���B
�@�����o�ϐ����|�C���^�ł��鎞�A�O���錾���g����B
  cpp�ŃC���N���[�h���K�v�Ȃ̂�cpp�̃C���N���[�h�͑�����B
  �|�C���^�ł͖������̂̃����o�ϐ��͏������ׂ̈Ƀw�b�_�̏�񂪕K�v�ɂȂ�B

2�D�X�}�[�g�|�C���^�ɂ�����őO���錾�ɂ���B
�@�|�C���^�ł͂Ȃ����̂Ƃ��ď����������N���X�́A���j�[�N�|�C���^�ɂ��Ă��قړ����悤�Ɉ�����B
  ���j�[�N�|�C���^�ɂ���ƃw�b�_����cpp�ɃC���N���[�h���ڂ����Ƃ��o����B

3�DPimpl�p�^�[�����g��
�@private�ϐ��A�֐��Ɍ����Ă͐錾�Ǝ�����cpp�ɉB����̂Ńw�b�_�ŃC���N���[�h����K�v�͖����B
  
*/

#include <memory>

//�C���N���[�h�����ɑO���錾
class Hoge1;
class Hoge2;

namespace ReduceInclude
{
	class Printer
	{
	public:
		Printer();
		~Printer();

		void PrintHoge1();
		void PrintHoge2();
		void PrintHoge3();

		//�֐��̈����Ƃ��Ă̓|�C���^�łȂ��Ă��O���錾�ł����炵��
		void Print( Hoge1 hoge1 );
		void Print( Hoge2 hoge2 );
		//void Print( Hoge3 hoge3 );

	//�m�F�p�Ƃ���private�ϐ���Pimpl�𓯋������Ă���
	private:
		Hoge1* m_hoge1;
		std::unique_ptr<Hoge2> m_hoge2;

	private:
		class PrinterImpl* m;
	};


	void Test();
}