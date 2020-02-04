#include "tList.h"
#include <iostream>

int main()
{
	tList<int> list;
	list.push_front(5);
	std::cout << "5 push front" << std::endl;
	list.push_back(2);
	std::cout << "2 push back" << std::endl;
	list.push_front(7);
	std::cout << "7 push front" << std::endl;
	list.push_front(1);
	std::cout << "1 push front" << std::endl;
	list.push_front(3);
	std::cout << "3 push front" << std::endl;
	list.push_back(12);
	std::cout << "12 push back" << std::endl;
	list.push_front(6);
	std::cout << "6 push front" << std::endl;
	list.push_front(4);
	std::cout << "4 push front" << std::endl;
	list.push_back(8);
	std::cout << "8 push back" << std::endl;
	list.push_front(12);
	std::cout << "12 push front" << std::endl;
	list.push_back(12);
	std::cout << "12 push back" << std::endl;
	list.remove(12);
	std::cout << "All 12s are removed" << std::endl;
	list.push_back(32);
	std::cout << "32 push back" << std::endl;
	list.push_back(32);
	std::cout << "32 push back" << std::endl;
	list.resize(8);
	std::cout << "list resized to 8" << std::endl;
	while (true)
	{

	}

	return 0;
}