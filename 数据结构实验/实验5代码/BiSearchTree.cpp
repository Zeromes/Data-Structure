// BiSearchTree.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

typedef int Datatype;
#define Max 10

template<class T>
class BiSearchTree;

template<class T>
class BTNode
{
	friend class BiSearchTree<T>;
	friend int myFind(BTNode<T>*& ptr, const T& item);
	friend void Visit(BTNode<T>* p);
	friend BTNode<T>* Find(BTNode<T>*& root, T item);
	friend BTNode<T>* copytree(BTNode<T>* oldroot);
private:
	T element;
	BTNode<T>* lc, * rc;
public:
	BTNode() { lc = rc = NULL; }
	BTNode(const T e)
	{
		element = e;
		lc = rc = NULL;
	}
	BTNode(const T e, BTNode<T>* l, BTNode<T>* r)
	{
		element = e;
		lc = l;
		rc = r;
	}
	BTNode(const BTNode<T>& a) // 拷贝构造函数
	{
		element = a->element;
		lc = a->lc;
		rc = a->rc;
	}
	BTNode<T>*& Left(void)
	{
		return lc;
	}
	BTNode<T>*& Right(void)
	{
		return rc;
	}
};

template<class T>
void Visit(BTNode<T>* p)
{
	cout << p->element << "  ";
}

template<class T>
class BiSearchTree
{
private:
	BTNode<T>* root;
	void PreOrder(BTNode<T>*& t);
	void InOrder(BTNode<T>*& t);
	void PostOrder(BTNode<T>*& t);
	void myOrder(BTNode<T>*& t);
	void Insert(BTNode<T>*& ptr, const T& item);
	void Delete(BTNode<T>*& ptr, const T& item);
public:
	BiSearchTree() { root = NULL; }
	~BiSearchTree() {};
	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }
	void myOrder() { myOrder(root); }

	BTNode<T>*& GetRoot() { return root; }
	BTNode<T>*& LeftChild(BTNode<T>*& current)
	{
		return root != NULL ? current->Left() : NULL;
	}
	BTNode<T>*& RightChild(BTNode<T>*& current)
	{
		return root != NULL ? current->Right() : NULL;
	}

	BTNode<T>*& Find(const T& item);
	void Insert(const T& item) { Insert(GetRoot(), item); }
	void Delete(const T& item) { Delete(GetRoot(), item); }

	friend istream& operator>>(istream& in, BiSearchTree<T>*& tree);
};

template<class T>
void BiSearchTree<T>::PreOrder(BTNode<T>*& t)
{
	if (t != NULL)
	{
		Visit(t);
		PreOrder(t->lc);
		PreOrder(t->rc);
	}
}

template<class T>
void BiSearchTree<T>::InOrder(BTNode<T>*& t)
{
	if (t != NULL)
	{
		InOrder(t->lc);
		Visit(t);
		InOrder(t->rc);
	}
}

template<class T>
void BiSearchTree<T>::PostOrder(BTNode<T>*& t)
{
	if (t != NULL)
	{
		PostOrder(t->lc);
		PostOrder(t->rc);
		Visit(t);
	}
}

template<class T>
void BiSearchTree<T>::myOrder(BTNode<T>*& t)
{
	if (t != NULL)
	{
		myOrder(t->rc);
		Visit(t);
		myOrder(t->lc);
	}
}

//查找的非递归算法
template<class T>
BTNode<T>*& BiSearchTree<T>::Find(const T& item)
{
	if (root != NULL)
	{
		BTNode<T>* temp = root;
		while (temp != NULL)
		{
			if (temp->element == item) return temp;
			if (temp->element < item) temp = temp->Right();
			else temp = temp->Left();
		}
	}
	return NULL;
}


template<class T>
void BiSearchTree<T>::Insert(BTNode<T>*& ptr, const T& item)
{
	if (ptr == NULL)
	{
		ptr = new BTNode<T>(item);
		if (ptr == NULL)
		{
			cerr << "空间不足！" << endl;
			exit(1);
		}
	}
	else if (item < ptr->element) Insert(ptr->Left(), item);
	else if (item > ptr->element) Insert(ptr->Right(), item);
	//否则就是item已在二叉排序树中，不做任何事
}

template<class T>
void BiSearchTree<T>::Delete(BTNode<T>*& ptr, const T& item)
{
	BTNode<T>* temp;
	if (ptr != NULL)
	{
		if (item < ptr->element)Delete(ptr->Left(), item);
		else if (item > ptr->element)Delete(ptr->Right(), item);

		else if (ptr->Left() != NULL && ptr->Right() != NULL)
		{
			BTNode<T>* min;
			min = ptr->Right();

			while (min->Left() != NULL)min = min->Left();

			ptr->element = min->element;

			Delete(ptr->Right(), min->element);
		}
		else
		{
			temp = ptr;

			if (ptr->Left() == NULL)ptr = ptr->Right();
			else if (ptr->Right() == NULL)ptr = ptr->Left();
			delete temp;
		}
	}
}

//查找的递归算法
template<class T>
int myFind(BTNode<T>*& ptr, const T& item)
{
	if (ptr != NULL)
	{
		if (ptr->element == item) return 1;
		if (ptr->element < item) return myFind(ptr->Right(), item);
		else return myFind(ptr->Left(), item);
	}
	else return 0;
}

int main()
{
	BiSearchTree<int> searchTree;

	time_t t;
	srand((unsigned)time(&t));

	for(int i=0;i<10;i++) searchTree.Insert(rand()%100);
	searchTree.InOrder();
	cout<<endl;
	searchTree.myOrder();
	cout<<endl;
	return 0;
}
