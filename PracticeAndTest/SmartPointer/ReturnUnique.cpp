#include "ReturnUnique.h"
#include <iostream>

namespace ReturnUnique
{
	BigData::BigData()
	{
		std::cout << "�R���X�g���N�^" << std::endl;
		ptr = new char[1000];
	}

	//�R�s�[�R���X�g���N�^
	BigData::BigData( const BigData& d )
	{
		std::cout << "�R�s�[�R���X�g���N�^" << std::endl;
		ptr = new char[1000];
		std::copy( d.ptr, d.ptr + 1000, ptr ); //���Ԃ�������炵���H�H
	}

	//�f�X�g���N�^
	BigData::~BigData()
	{
		delete[] ptr;
	}


	BigData MakeData()
	{
		BigData data; //���[�J���ŃC���X�^���X���쐬
		return data; //���̃R�s�[��Ԃ�
	}

	BigData* MakeDataP()
	{
		BigData* pData = new BigData(); //�q�[�v�ɃC���X�^���X���쐬
		return pData; //���̃A�h���X��Ԃ�
	}

	std::unique_ptr<BigData> MakeDataU()
	{
		//make_unique���g���ƃR�s�[�R���X�g���N�^�������Ă��� �Ȃ񂾂��̗��؂��
		//auto upData = std::make_unique<BigData>( BigData() );

		auto upData = std::unique_ptr<BigData>( new BigData() );
		return upData; //�E�Ӓl���ǂ��̂�unique_ptr�����̂܂ܕԂ����Ƃ��ł���
	}

	void Test()
	{
		std::cout << "�R�s�[��Ԃ��ꍇ" << std::endl;
		BigData data = MakeData();

		std::cout << std::endl << "�|�C���^��Ԃ��ꍇ" << std::endl;
		BigData* p = MakeDataP();
		delete p; //delete��Y���ƃ��������[�N����@�댯

		std::cout << std::endl << "���j�[�N�|�C���^��Ԃ��ꍇ" << std::endl;
		auto up = MakeDataU();

	}
}