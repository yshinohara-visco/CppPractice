#pragma once

/*
�X�}�[�g�|�C���^�͐��|�C���^�Ɣ�ׂ�ƃA�N�Z�X���̃I�[�o�[�w�b�h���傫���炵��
���ۂǂꂭ�炢�̍��ɂȂ�̂��H
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