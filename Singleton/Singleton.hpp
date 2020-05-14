//! Singleton Naive Implementation
//! Non thread safe implementation
#include <iostream>

class Singleton
{
private:
	Singleton();
	~Singleton();
	static Singleton* instance;

public:

	static Singleton* GetInstance();
	static void     	 Destroy();
};


Singleton::Singleton()
{
	std::cout<<"construct global singleton object\t"<<this<<std::endl;
}

Singleton::~Singleton()
{
	std::cout<<"destruct  global singleton object\t"<<this<<std::endl;
}


Singleton* Singleton::GetInstance()
{
	if (instance == nullptr)
		instance = new Singleton();

	return instance;
}


void Singleton::Destroy()
{
	if(instance)
		delete instance;
	instance = nullptr;
}

Singleton* Singleton::instance = nullptr;




