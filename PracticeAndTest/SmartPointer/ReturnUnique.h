#pragma once

#include <vector>
#include <memory>
#include <iostream>

namespace ReturnUnique
{
	/*
	�������𑽂��m�ۂ���N���X���������Ƃ��āA����̍쐬����֐�����肽���B
	���ʂɕԂ��ƃR�s�[���Ă��܂��̂����B
	new���ă|�C���^��Ԃ���delete�Y�ꂪ�|���B
	unique_ptr�Ȃ�֐����ō쐬�����C���X�^���X�����L���n�����ƂŁA
	�R�s�[�����ŏ����Y��̐S�z���Ȃ��B�炵���B
	*/

	class BigData
	{
	public:
		BigData();

		//�R�s�[�R���X�g���N�^
		BigData( const BigData& d );

		//�f�X�g���N�^
		~BigData();

	private:
		char* ptr;
	};

	BigData MakeData();
	BigData* MakeDataP();
	std::unique_ptr<BigData> MakeDataU();

	void Test();
};

