#pragma once

#include <variant>
#include <string>
#include <iostream>

/*
variant�͌p���֌W�ɂȂ������̌^��P��̃I�u�W�F�N�g�ɑ���E�ؑւ��ł���B
�񋓂����^�𓯈�I�u�W�F�N�g�Ƃ��Ĉ�����_�ő��Ԑ���\�����Ă���B
�r�W�^�[�֐��I�u�W�F�N�g�ɂ���Č^���Ƃ̓�����`�ł���B

�Ԃ�l�𑵂���K�v������B
�p���֌W�ɂ���N���X������đ��Ԑ����g�����炢���̂ł́H�H�H
*/
namespace Variant
{
	void Test1();


	/*
	�������A���s����2��ނ̌��ʃf�[�^��Ԃ��\��������֐����`�����Ƃ��āA
	���̏ꍇ��2�̐eResult�Ƃ����`���Čp�������������Ε�����₷��
	*/
	class ResultSuccess
	{
	public:
		void Print() { std::cout << "Result: Success" << std::endl; }
	};

	class ResultFailure
	{
	public:
		void Print() { std::cout << "Result: Failure" << std::endl; }
		void Why() { std::cout << "siran" << std::endl; }
	};

	std::variant<ResultSuccess, ResultFailure> GetResult( bool b );
	void Test2();
}