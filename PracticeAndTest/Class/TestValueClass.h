#pragma once

#include <memory>

/*
値や文字列を持ったクラスがある時、値をそのままにintやdoubleで持ち、引数で受け取ると
クラスのルールに違反する値を受け取ったり持ったりしやすくなる。
値が条件を見たいしているか外で判定なんてしているとあちこちで似たような判定をすることになる

値そのものをクラスにしてルール付けなどを中に含めてしまう
らしいが上手い感じのしっくりくる実装にならない
*/

namespace TestValueClass
{
	/*
	スコアを持つHOGEが有り、スコアは0～100だとする
	*/
#define MAX 100
#define MIN 0

	//不正値を渡すことができ、プログラム的には動き続けてしまうクラス
	class HOGE1
	{
	public:
		void Set( int score )
		{
			m_score = score;
		}
		int Get()
		{
			return m_score;
		}

		void Add( int add )
		{
			m_score += add;
		}

	private:
		int m_score = 0;
	};

	//不整地を渡すとエラーになるクラス
	//他にスコアを扱うクラスを実装した時、同じ判定をそこにも追加する必要がある
	class HOGE2
	{
	public:
		void Set( int score )
		{
			if (score < MIN || MAX < score)
			{
				throw("スコアが範囲外です");
			}
			m_score = score;
		}
		int Get()
		{
			return m_score;
		}

		void Add( int add )
		{
			if (m_score + add > MAX)
			{
				throw("スコアがMAXを超えます");
			}
			m_score += add;
		}

	private:
		int m_score = 0;
	};

	//-------------

	//なんだかしっくりこない
	class Score
	{
	public:
		Score( int value )
			:m_value( CanConstract( value ) )
		{}

		int Value() const
		{
			return m_value;
		}
		
		Score Add( const Score& add )
		{
			CanAdd( add );
			return Score( m_value + add.Value() );
		}

	private:
		const int max = 100;
		const int min = 0;
		const int m_value;

		const int& CanConstract( int value = 0 ) const
		{
			if (value < min || max < value)
			{
				throw("スコアが範囲外です");
			}
			return value;
		}

		void CanAdd( const Score& add) const
		{
			if (m_value + add.Value() > max)
			{
				throw("スコアがMAXを超えます");
			}
		}

	};

	class HOGE3
	{
	public:
		void Set( Score score )
		{
			m_score = std::make_unique<Score>( score.Value() );
		}

		std::unique_ptr<Score>& Get()
		{
			return m_score;
		}

		void Add( Score add )
		{
			m_score->Add( add );
		}

	private:
		std::unique_ptr<Score> m_score;
	};

	void TestMethod1();
}