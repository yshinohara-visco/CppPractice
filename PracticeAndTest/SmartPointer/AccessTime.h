#pragma once

/*
�X�}�[�g�|�C���^�͐��|�C���^�Ɣ�ׂ�ƃA�N�Z�X���̃I�[�o�[�w�b�h���傫���炵��
���ۂǂꂭ�炢�̍��ɂȂ�̂��H

unique_ptr�͍폜���鎞�Ashared_ptr�̓J�E���^�̑����폜�����鎞�ɃI�[�o�[�w�b�h��������炵��
�A�N�Z�X���J��Ԃ����Ԃ��ׂĂ��Ӗ��͔��������B
*/

#include <chrono>

namespace AccessTime
{
	class Timer
	{
	public:
		void Start();
		double Get();

	private:
		std::chrono::system_clock::time_point m_start;
	};

	void Test();
}