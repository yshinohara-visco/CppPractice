#include "BufferReadWrite.h"
#include <iostream>
#include <float.h>

namespace BufferReadWrite
{

	/*
	�|�C���^���g���ă������ɓǂݏ�������
	�|�C���^���w���Ԓn���o�b�t�@�͈̔͂𒴂�����A�o�b�t�@���������Ă���O�͓������Ȃ�
	m_point���̂�nullptr�ɂȂ����肵�Ȃ��Ɨ�O�͓������Ȃ�
	*/

	void Test()
	{
		//1byte��20�񏑂���20���ǂݍ���
		{
			BufferHolder holder( 20 );

			auto ptrWrite = holder.GetPointer();
			int count = 0;
			while (nullptr != ptrWrite.Append( unsigned char( count ) ))
			{
				std::cout << "Append : " << count << std::endl;
				count += 1;
			}

			auto ptrRead = holder.GetPointer();
			unsigned char value;
			while (nullptr != ptrRead.Read( value ))
			{
				std::cout << "Read : " << (int)value << std::endl;
			}
		}

		std::cout << std::endl;

		//4byte��3�񏑂���3��ǂݍ���
		{
			BufferHolder holder( 10 );

			auto ptrWrite = holder.GetPointer();
			auto appendShow = [&]( int32_t value )
			{
				if (nullptr != ptrWrite.Append( value ))
				{
					std::cout << "Append2 : " << value << std::endl;
				}
			};
			appendShow( 1 );
			appendShow( 2 );
			appendShow( 3 ); //�͂ݏo��̂Œ��f

			auto ptrRead = holder.GetPointer();
			auto readShow = [&]()
			{
				int32_t value;
				if (nullptr != ptrRead.Read( value ) )
				{
					std::cout << "Read2 : " << value << std::endl;
				}
			};
			readShow();
			readShow();
			readShow(); //�͂ݏo��̂Œ��f
		}

		std::cout << std::endl;

		//�͈͊O�ł͂ǂ��Ȃ�H
		{
			BufferHolder holder( 10 );

			auto ptrWrite = holder.GetPointer();
			auto appendShow = [&]( int32_t value )
			{
				if (nullptr != ptrWrite.AppendForTest( value ))
				{
					std::cout << "AppendForTest : " << value << std::endl;
				}
			};
			appendShow( 1 );
			appendShow( 2 );
			//appendShow( 3 ); //�͈͊O�����݂Ń������j�󂷂邪��O�͓����Ȃ�
			//appendShow( 4 ); //�͈͊O�����݂Ń������j�󂷂邪��O�͓����Ȃ�
			//appendShow( 5 ); //�͈͊O�����݂Ń������j�󂷂邪��O�͓����Ȃ�

			auto ptrRead = holder.GetPointer();
			auto readShow = [&]()
			{
				int32_t value;
				if (nullptr != ptrRead.ReadForTest( value ))
				{
					std::cout << "ReadForeDebug : " << value << std::endl;
				}
			};
			readShow();
			readShow();
			//readShow(); //���ŏ������񂾂Ƃ����ǂނ̂œǂ߂Ă��܂�
			//readShow(); //���ŏ������񂾂Ƃ����ǂނ̂œǂ߂Ă��܂�
			//readShow(); //���ŏ������񂾂Ƃ����ǂނ̂œǂ߂Ă��܂�
		}

		std::cout << std::endl;

		//�Ǎ����ɉ�����ꂽ��ǂ��Ȃ�H
		{
			BufferHolder* holder = new BufferHolder( 20 );

			auto ptrWrite = holder->GetPointer();
			auto appendShow = [&]( int32_t value )
			{
				if (nullptr != ptrWrite.Append( value ))
				{
					std::cout << "Append3 : " << value << std::endl;
				}
			};
			appendShow( 1 );
			appendShow( 2 );
			appendShow( 3 );
			//delete holder; //�����ŉ������Ǝ���GetPointer�ŕs��l���Ԃ�
			appendShow( 4 );
			appendShow( 5 );

			auto ptrRead = holder->GetPointer();
			auto readShow = [&]()
			{
				int32_t value;
				if (nullptr != ptrRead.Read( value ))
				{
					std::cout << "Read3 : " << value << std::endl;
				}
			};
			readShow();
			readShow();
			readShow();
			delete holder; //�o�b�t�@�����
			readShow(); //�l�͋�������O�͏o�Ȃ�
			readShow(); //�l�͋�������O�͏o�Ȃ�
		}

		std::cout << std::endl;
		
		//�Ǎ����ɕʂ̓��e���������񂾂�H
		{
			BufferHolder* holder = new BufferHolder( 20 );

			auto ptrWrite = holder->GetPointer();
			auto appendShow = [&]( int32_t value )
			{
				if (nullptr != ptrWrite.Append( value ))
				{
					std::cout << "Append4 : " << value << std::endl;
				}
			};
			appendShow( 1 );
			appendShow( 2 );
			appendShow( 3 );
			appendShow( 4 );
			appendShow( 5 );

			auto ptrRead = holder->GetPointer();
			auto readShow = [&]()
			{
				int32_t value;
				if (nullptr != ptrRead.Read( value ))
				{
					std::cout << "Read4 : " << value << std::endl;
				}
			};
			readShow();
			readShow();
			readShow();

			//�ʂ̓��e����������
			auto ptrWrite2 = holder->GetPointer();
			auto appendShow2 = [&]( double value )
			{
				if (nullptr != ptrWrite2.Append( value ))
				{
					std::cout << "Append4-2 : " << value << std::endl;
				}
			};
			appendShow2( 1 );
			appendShow2( 2 );
			appendShow2( 3 );


			readShow(); //�l�͋�������O�͏o�Ȃ�
			readShow(); //�㏑���Ă��Ȃ��̂Ō��̒l
		}

		std::cout << std::endl;

		//m_point��nullptr�ɂȂ�����H
		{
			BufferHolder* holder = new BufferHolder( 20 );

			auto ptrWrite = holder->GetPointer();
			ptrWrite.BreakPointForTest();
			//ptrWrite.Append( int( 0 ) ); //��O�𓊂���
		}


		//1byte��20�񏑂���20���ǂݍ���
		{
			BufferHolder holder( 20 );

			auto ptrWrite = holder.GetPointer();
			int count = 0;
			while (nullptr != ptrWrite.Append( unsigned char( count ) ))
			{
				std::cout << "Append : " << count << std::endl;
				count += 1;
			}

			auto ptrRead = holder.GetPointer();
			unsigned char value;
			while (nullptr != ptrRead.Read2( value ))
			{
				std::cout << "Read : " << (int)value << std::endl;
			}
		}

		std::cout << std::endl;

		//4byte��3�񏑂���3��ǂݍ���
		{
			BufferHolder holder( 10 );

			auto ptrWrite = holder.GetPointer();
			auto appendShow = [&]( int32_t value )
			{
				if (nullptr != ptrWrite.Append2( value ))
				{
					std::cout << "Append2 : " << value << std::endl;
				}
			};
			appendShow( 1 );
			appendShow( 2 );
			appendShow( 3 ); //�͂ݏo��̂Œ��f

			auto ptrRead = holder.GetPointer();
			auto readShow = [&]()
			{
				int32_t value;
				if (nullptr != ptrRead.Read2( value ))
				{
					std::cout << "Read2 : " << value << std::endl;
				}
			};
			readShow();
			readShow();
			readShow(); //�͂ݏo��̂Œ��f
		}

		{
			BufferHolder holder( 8 * 1024 * 1024 );
			auto ptrWrite = holder.GetPointer();
			double value = 0;
			unsigned int count = 0;

			while (true)
			{
				while (nullptr != ptrWrite.Append(value++))
				{
				}
				std::cout << "loop " << count++ << std::endl;
				value = 0;
				ptrWrite = holder.GetPointer();
			}
		}
	}
}