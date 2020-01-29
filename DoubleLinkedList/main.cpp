#include "tList.h"

int main()
{
	tList<int> list;
	list.push_front(5);
	list.push_back(2);
	list.push_front(7);
	list.push_front(1);
	list.push_front(3);
	list.push_back(12);
	list.push_front(6);
	list.push_front(4);
	list.push_back(8);
	list.push_front(12);
	list.push_back(12);
	list.remove(12);
	list.push_back(32);
	list.push_back(32);
	list.resize(8);
	//list.bubbleSort();

	while (true)
	{

	}

	return 0;
}