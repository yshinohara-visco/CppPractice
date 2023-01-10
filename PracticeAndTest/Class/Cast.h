#pragma once

namespace Cast
{
	class Holder
	{
	public:
		template <class T>
		void Set( T value )
		{
			if (m_pointer)
			{
				delete m_pointer;
			}

			int size = sizeof( T );
			m_pointer = new char[ size ];
			*reinterpret_cast<T*>( m_pointer ) = value;
		}

		template <class T>
		void Get( T& value )
		{
			value = *reinterpret_cast<T*>(m_pointer);
		}

		template <class T>
		T Get()
		{
			T value;
			Get( value );
			return value;
		}

	private:
		char* m_pointer = nullptr;
	};

	void Test();
}