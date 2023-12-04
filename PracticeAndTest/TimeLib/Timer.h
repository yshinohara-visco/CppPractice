#pragma once

#include <chrono>
#include <vector>
#include <functional>

namespace Time
{
	class Timer
	{
	public:
		//計測開始
		void Start();
		//Startからの経過時間msを取得
		double Get();

	private:
		std::chrono::system_clock::time_point m_start;
	};

	//funcをcountLoop回実行する処理をcountAverage回実行し、各時間をvecTimeに、平均時間をaverageに格納する
	void MeasureTime( std::function<void()> func, int countAverage, int countLoop, double& average, std::vector<double>& vecTime );
	
	//funcをcountLoop改実行する処理をcountAverage改実行した平均を返す
	double MeasureTime( std::function<void()> func, int countAverage = 1, int countLoop = 1 );

}