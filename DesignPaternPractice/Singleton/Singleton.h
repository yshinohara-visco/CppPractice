#pragma once
//教本のが動かないのでネットのを真似
//https://qiita.com/kikuuuty/items/fcf5f7df2f0493c437dc

#include <cassert>
#include <mutex>

class SingletonFinalizer
{
public:
	using FinalizerFunc = void(*)();
	static void addFinalizer(FinalizerFunc func);
	static void finalize();
};


template <typename T>
class Singleton final
{
public:
	static T& get_instance()
	{
		std::call_once(initFlag, create);
		assert(instance);// instanceが真か判定　インスタンスがちゃんとあるか確認
		return *instance;
	}

private:
	static void create()
	{
		instance = new T;
		SingletonFinalizer::addFinalizer(&Singleton<T>::destroy);
	}

	static void destroy()
	{
		delete instance;
		instance = nullptr;
	}

	//staticメンバ変数の宣言
	static std::once_flag initFlag;
	static T* instance;
};

//staticメンバ変数の定義
template <typename T> std::once_flag Singleton<T>::initFlag;
template <typename T> T* Singleton<T>::instance = nullptr;