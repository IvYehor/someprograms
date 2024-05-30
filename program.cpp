#include <iostream>
#include <utility>
#include "logger.h"
#define USELOGGING
#include "unique.h"

int main(){
	
	my_unique_ptr<int> p1(new int(2));
	my_unique_ptr<int> p2(std::move(p1));
	//long long a = 5;
	//std::cout << &a << '\n';
	//std::cout << sizeof a << '\n';
	//std::cout << &a + 1 << '\n';
	//std::cout << (void*)&a + 1 << '\n';
	//auto aa = 1;
	//decltype(aa) bb = 2;

	//Logger *log = new ConsoleLogger();

	//log->debug("Hi there!");
}
