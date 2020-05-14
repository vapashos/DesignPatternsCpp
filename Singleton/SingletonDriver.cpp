#include "Singleton.hpp"
#include <iostream>


int main(void)
{
	Singleton* singletonInstance = nullptr;

	//! We expect only one instance to be created
	for(uint8_t i=0;i<10;i++)
		singletonInstance = Singleton::GetInstance();

	//! Destroy and create again
	Singleton::Destroy();

	//! Destroy and create again
	singletonInstance = Singleton::GetInstance();

	return 1;
}
