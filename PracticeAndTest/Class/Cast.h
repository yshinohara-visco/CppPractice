#pragma once
#include <memory>
#include <iostream>

namespace Cast
{
	class Holder
	{
	public:
		template <class T>
		void Set( T value )
		{
			int size = sizeof( T );
			m_buffer = std::make_unique<char[]>( size );
			*reinterpret_cast<T*>( m_buffer.get() ) = value;
		}

		template <class T>
		void Get( T& value )
		{
			if (!m_buffer)
			{
				std::cout << "buffer is null" << std::endl;
				return;
			}

			value = *reinterpret_cast<T*>(m_buffer.get());
		}

		template <class T>
		T Get()
		{
			T value;
			Get( value );
			return value;
		}

	private:
		std::unique_ptr<char[]> m_buffer;
	};

	void Test();
}