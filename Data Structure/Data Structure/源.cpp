#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int x = 0) { data = x; next = NULL; }
};

void CreateList(Node*& Head)//创建链表
{
	Node* p = Head;
	int temp;
	cout << "结点个数:";
	cin >> Head->data;
	if (Head->data > 0)
	{
		for (int i = 0; i < Head->data; i++)
		{
			cin >> temp;
			p->next = new Node(temp);
			p = p->next;
		}
	}
}

void ShowList(Node* Head)//输出链表
{
	if (Head != NULL)
	{
		cout << Head->data << endl;
		ShowList(Head->next);
	}
}

void DeleteNode(Node* Head, int ItemInfo, bool Type)
{
	if (Type) //删除第Iteminfo个结点
	{
		Node* p = Head, * s;
		for (int i = 0; i < ItemInfo - 1; i++)
			p = p->next;
		s = p->next;
		p->next = s->next;
		delete s;
		Head->data--;
	}
	else    //删除值为Iteminfo的结点
	{
		Node* p = Head->next, * front = Head;
		while (p != NULL)
		{
			if (p->data == ItemInfo)
			{
				front->next = p->next;
				delete p;
				Head->data--;
				p = front->next;
				continue;
			}
			p = p->next;
			front = front->next;
		}
	}
}

//删除单链表第i个结点或值为val的结点
//bool类变量Type为true时函数功能为删除第i个结点
//为false时函数功能为删除值为val的结点
//头结点不参与删除

int main()
{
	Node* List1 = new Node;
	Node* List2 = new Node;
	CreateList(List1);
	DeleteNode(List1, 1, true);
	cout << "List1:" << endl;
	ShowList(List1->next);//头结点存储结点数，这里跳过
	cout << "——————————" << endl;//分割线
	CreateList(List2);
	DeleteNode(List2, 8, false);
	cout << "List2:" << endl;
	ShowList(List2->next);//头结点存储结点数，这里跳过
}