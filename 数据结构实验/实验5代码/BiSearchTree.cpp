// BiSearchTree.cpp : Defines the entry point for the console application.
//

#include "BiSearchTree.h"
#include <cstdlib>
#include <ctime>
using namespace std;

typedef int Datatype;
#define Max 10

void main(void)
{
	BiSearchTree<int> searchTree;

	time_t t;
	srand((unsigned)time(&t));

	for(int i=0;i<10;i++) searchTree.Insert(rand()%100);
	searchTree.InOrder();
	cout<<endl;
	searchTree.myOrder();
	cout<<endl;
}
