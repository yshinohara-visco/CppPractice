#pragma once

#include <atomic>

namespace Atomic
{

	/*
	�X�s�����b�N��mutex�ŁA���b�N���鎞�Ԃ��������Z�����Ŏg������������炵��
	�X�s�����b�N�̓��b�N�A�A�����b�N�̃R�X�g���Ⴂ�����b�N�𑱂���R�X�g������
	mutex�̓��b�N�A�A�����b�N�̃R�X�g�����������b�N�𑱂���R�X�g�͒Ⴂ�@�炵��
	�Z���ԍ��p�x���b�N���X�s�����b�N�@�����Ԓ�p�x���b�N��mutex �݂����ȁH
	���b�N���Ǝ��s���̈ێ��Ƃ����֌W���肻��
	*/
	class SpinLock
	{
	private:
		enum LockState
		{
			Locked,
			Unlocked,
		};

	public:
		SpinLock();

		void lock();
		void unlock();

	private:
		std::atomic<LockState> m_state;
	};

	void Test();

}