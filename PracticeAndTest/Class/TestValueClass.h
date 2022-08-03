#pragma once

#include <memory>

/*
�l�╶������������N���X�����鎞�A�l�����̂܂܂�int��double�Ŏ����A�����Ŏ󂯎���
�N���X�̃��[���Ɉᔽ����l���󂯎�����莝�����肵�₷���Ȃ�B
�l�����������������Ă��邩�O�Ŕ���Ȃ�Ă��Ă���Ƃ��������Ŏ����悤�Ȕ�������邱�ƂɂȂ�

�l���̂��̂��N���X�ɂ��ă��[���t���Ȃǂ𒆂Ɋ܂߂Ă��܂�
�炵������肢�����̂������肭������ɂȂ�Ȃ�
*/

namespace TestValueClass
{
	/*
	�X�R�A������HOGE���L��A�X�R�A��0�`100���Ƃ���
	*/
#define MAX 100
#define MIN 0

	//�s���l��n�����Ƃ��ł��A�v���O�����I�ɂ͓��������Ă��܂��N���X
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

	//�s���n��n���ƃG���[�ɂȂ�N���X
	//���ɃX�R�A�������N���X�������������A��������������ɂ��ǉ�����K�v������
	class HOGE2
	{
	public:
		void Set( int score )
		{
			if (score < MIN || MAX < score)
			{
				throw("�X�R�A���͈͊O�ł�");
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
				throw("�X�R�A��MAX�𒴂��܂�");
			}
			m_score += add;
		}

	private:
		int m_score = 0;
	};

	//-------------

	//�Ȃ񂾂��������肱�Ȃ�
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
				throw("�X�R�A���͈͊O�ł�");
			}
			return value;
		}

		void CanAdd( const Score& add) const
		{
			if (m_value + add.Value() > max)
			{
				throw("�X�R�A��MAX�𒴂��܂�");
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