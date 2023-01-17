#pragma once
#include <memory>
#include <iostream>

namespace BufferReadWrite
{
	class BufferPointer
	{
	public:
		BufferPointer( char* buffer, int length )
			:m_buffer( buffer ),
			m_point( buffer ),
			m_last( buffer + length )
		{
		}

		template <typename T>
		char* Append( const T& value )
		{
			if ((m_point + sizeof( T )) > m_last)
			{
				std::cout << "Append over last-point:" << m_last - m_point << " size:" << sizeof( T ) << std::endl;
				return nullptr;
			}
			*reinterpret_cast<T*>(m_point) = value;
			m_point += sizeof( T );
			return m_point;
		}

		template <typename T>
		char* Read( T& value )
		{
			if ((m_point + sizeof( T )) > m_last)
			{
				std::cout << "Read over last-point:" << m_last - m_point << " size:" << sizeof( T ) << std::endl;
				return nullptr;
			}
			value = *reinterpret_cast<T*>(m_point);
			m_point += sizeof( T );
			return m_point;
		}

		template <typename T>
		char* AppendForTest( T& value )
		{
			//範囲外でも書き込んでしまい例外を投げない
			*reinterpret_cast<T*>(m_point) = value;
			m_point += sizeof( T );
			return m_point;
		}


		template <typename T>
		char* ReadForTest( T& value )
		{
			//範囲外でも読み込めてしまい例外を投げない
			value = *reinterpret_cast<T*>(m_point);
			m_point += sizeof( T );
			return m_point;
		}

		void BreakPointForTest()
		{
			m_point = nullptr;
		}


	private:
		char* m_buffer;
		char* m_point;
		char* m_last;
	};

	class BufferHolder
	{
	public:
		BufferHolder( int size )
			:m_size(size)
		{
			m_buffer = std::make_unique<char[]>( size );
		}

		BufferPointer GetPointer()
		{
			return BufferPointer( m_buffer.get(), m_size );
		}

	private:
		std::unique_ptr<char[]> m_buffer;
		int m_size;
	};




	void Test();
}