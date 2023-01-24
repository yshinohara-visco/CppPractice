#include "BufferReadWrite.h"
#include <iostream>
#include <float.h>

namespace BufferReadWrite
{

	/*
	ポインタを使ってメモリに読み書きする
	ポインタが指す番地がバッファの範囲を超えたり、バッファが解放されても例外は投げられない
	m_point自体がnullptrになったりしないと例外は投げられない
	*/

	void Test()
	{
		//1byteを20回書いて20改読み込む
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

		//4byteを3回書いて3回読み込む
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
			appendShow( 3 ); //はみ出るので中断

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
			readShow(); //はみ出るので中断
		}

		std::cout << std::endl;

		//範囲外ではどうなる？
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
			//appendShow( 3 ); //範囲外書込みでメモリ破壊するが例外は投げない
			//appendShow( 4 ); //範囲外書込みでメモリ破壊するが例外は投げない
			//appendShow( 5 ); //範囲外書込みでメモリ破壊するが例外は投げない

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
			//readShow(); //↑で書き込んだところを読むので読めてしまう
			//readShow(); //↑で書き込んだところを読むので読めてしまう
			//readShow(); //↑で書き込んだところを読むので読めてしまう
		}

		std::cout << std::endl;

		//読込中に解放されたらどうなる？
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
			//delete holder; //ここで解放すると次のGetPointerで不定値が返る
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
			delete holder; //バッファを解放
			readShow(); //値は狂うが例外は出ない
			readShow(); //値は狂うが例外は出ない
		}

		std::cout << std::endl;
		
		//読込中に別の内容を書き込んだら？
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

			//別の内容を書き込み
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


			readShow(); //値は狂うが例外は出ない
			readShow(); //上書していないので元の値
		}

		std::cout << std::endl;

		//m_pointがnullptrになったら？
		{
			BufferHolder* holder = new BufferHolder( 20 );

			auto ptrWrite = holder->GetPointer();
			ptrWrite.BreakPointForTest();
			//ptrWrite.Append( int( 0 ) ); //例外を投げる
		}


		//1byteを20回書いて20改読み込む
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

		//4byteを3回書いて3回読み込む
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
			appendShow( 3 ); //はみ出るので中断

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
			readShow(); //はみ出るので中断
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