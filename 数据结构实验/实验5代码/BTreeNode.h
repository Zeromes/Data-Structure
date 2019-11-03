// BTree.cpp : Defines the entry point for the console application.
//

#include "iostream.h"
#include "stdlib.h"

template<class T>
class BiSearchTree;


template<class T>
class BTNode
{
	friend class BiSearchTree<T>;
	friend int myFind(BTNode<T> *&ptr,const T &item);
	friend void Visit(BTNode<T> *p);
	friend BTNode<T>* Find(BTNode<T>* &root,T item);
	friend BTNode<T>* copytree(BTNode<T>* oldroot);
	private:
		T element;
		BTNode<T> *lc,*rc;
	public:
		BTNode(){lc=rc=NULL;}
		BTNode(const T e)
		{
			element=e;
			lc=rc=NULL;
		}
		BTNode(const T e,BTNode<T> *l,BTNode<T> *r)
		{
			element=e;
			lc=l;
			rc=r;
		}
		BTNode(const BTNode<T> &a) // ¿½±´¹¹Ôìº¯Êý
		{ 
			element=a->element;
			lc=a->lc;
			rc=a->rc;
		}
		BTNode<T>* &Left(void)
		{ return lc; }
		BTNode<T>* &Right(void) 
		{ return rc; }
};

template<class T>
void Visit(BTNode<T> *p)
{
	cout<<p->element<<"  ";
}

