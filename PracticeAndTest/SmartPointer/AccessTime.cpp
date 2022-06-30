#include "AccessTime.h"

#include <vector>
#include <memory>
#include <functional>
#include <iostream>

namespace AccessTime
{
	void Timer::Start()
	{
		m_start = std::chrono::system_clock::now();
	}

	double Timer::Get()
	{
		auto end = std::chrono::system_clock::now();
		auto diff = end - m_start;
		auto micro = std::chrono::duration_cast<std::chrono::microseconds>(diff);
		double ms = micro.count() / 1000.0;
		return ms;
	}

	class TestClass
	{
	public:
		void Add()
		{
			m_i += 1;
		}

	private:
		int m_i = 0;
	};

	void Test()
	{
		//時間の計測
		int loopCount = 1000000; //100万回
		int averageCount = 50; //50回
		Timer timer;

		auto timetest = [&]( std::function<void()> func, double& average, std::vector<double>& vecTime )
		{
			for (int i = 0; i < averageCount; i++)
			{
				timer.Start();
				for (int j = 0; j < loopCount; j++)
				{
					func();
				}
				double time = timer.Get();
				average += time;
				vecTime.push_back( time );
			}
			average = average / vecTime.size();
		};

		double  rawTime, shareTime, uniqueTime; //平均時間
		rawTime = shareTime = uniqueTime = 0;
		std::vector<double> vecRawTime, vecShareTime, vecUniqueTime; //各時間

		TestClass t;
		TestClass* pT = &t;

		std::shared_ptr<TestClass> spT = std::make_shared<TestClass>( TestClass() );
		std::unique_ptr<TestClass> upT = std::make_unique<TestClass>( TestClass() );

		std::cout << "生ポインタの計測開始" << std::endl;
		timetest( [&]() { pT->Add(); }, rawTime, vecRawTime );
		std::cout << "Sharedポインタの計測開始" << std::endl;
		timetest( [&]() { spT->Add(); }, shareTime, vecShareTime );
		std::cout << "Uniqueポインタの計測開始" << std::endl;
		timetest( [&]() { upT->Add(); }, uniqueTime, vecUniqueTime );

		std::cout <<
			"Raw : " << rawTime << std::endl <<
			"Shared : " << shareTime << std::endl <<
			"Unique : " << uniqueTime << std::endl;

		/*
		100万回のアクセスを50回行った平均
		
		Debug x64 の時の結果
		Raw : 110.52
		Shared : 132.905
		Unique : 121.266

		Release x64 の時の結果
		Raw : 1.3107
		Shared : 1.31206
		Unique : 1.30816
		*/
	}
}