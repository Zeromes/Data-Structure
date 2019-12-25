//BiSerchTree.cpp
//

#include"BiSearchTree.h"
#include <iostream>
#include<ctime>

int main()
{
	BiSearchTree<int> searchTree;

	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < 10; i++) searchTree.Insert(rand() % 100);
	searchTree.InOrder();
	cout << endl;
	searchTree.myOrder();
	cout << endl;
	return 0;
}