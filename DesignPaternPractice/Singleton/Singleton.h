#pragma once
//���{�̂������Ȃ��̂Ńl�b�g�̂�^��
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
		assert(instance);// instance���^������@�C���X�^���X�������Ƃ��邩�m�F
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

	//static�����o�ϐ��̐錾
	static std::once_flag initFlag;
	static T* instance;
};

//static�����o�ϐ��̒�`
template <typename T> std::once_flag Singleton<T>::initFlag;
template <typename T> T* Singleton<T>::instance = nullptr;