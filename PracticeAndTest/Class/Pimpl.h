#pragma once
#include <string>

/*
Impl�N���X�݂̂��v���C�x�[�g�ϐ��Ƃ��Ď���
���Xprivate�Ő錾���Ă����ϐ��A�֐���Impl�N���X��cpp�Ő錾�A��`����
�w�b�_����private�̏������S�ɉB�����Ƃ��ł���
�@+ pritvate�����̕ύX�Ńw�b�_��ҏW����K�v�������Ȃ�
  + private�p�̃C���N���[�h���w�b�_�ł��Ȃ��ėǂ��Ȃ�
  + ���ɂ���ăR���p�C�����Ԃ̒Z�k��_����
  - ���������ʓ|������
  - �R���X�g���N�^�������Ȃ�
  - Impl�̍폜��Y�ꂸ�ɍs���K�v������
  - �ǂ݂ɂ���

�l�I�ɂ͂��̃p�^�[���Ɋ���Ă��Ȃ��Ɠǂނ̂����J�Ȃ̂ōD���ł͂Ȃ�
�������b�g���傫���̂��m��
*/

namespace Pimpl
{
	class Printer
	{
	public:
		Printer( std::string str );
		~Printer();

		void Print();

	private:
		class PrinterImpl* m;
	};

	void Test();
}