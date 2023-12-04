#pragma once

#include <chrono>
#include <vector>
#include <functional>

namespace Time
{
	class Timer
	{
	public:
		//�v���J�n
		void Start();
		//Start����̌o�ߎ���ms���擾
		double Get();

	private:
		std::chrono::system_clock::time_point m_start;
	};

	//func��countLoop����s���鏈����countAverage����s���A�e���Ԃ�vecTime�ɁA���ώ��Ԃ�average�Ɋi�[����
	void MeasureTime( std::function<void()> func, int countAverage, int countLoop, double& average, std::vector<double>& vecTime );
	
	//func��countLoop�����s���鏈����countAverage�����s�������ς�Ԃ�
	double MeasureTime( std::function<void()> func, int countAverage = 1, int countLoop = 1 );

}