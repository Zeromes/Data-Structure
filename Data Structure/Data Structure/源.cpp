#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int x = 0) { data = x; next = NULL; }
};

void CreateList(Node*& Head)//��������
{
	Node* p = Head;
	int temp;
	cout << "������:";
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

void ShowList(Node* Head)//�������
{
	if (Head != NULL)
	{
		cout << Head->data << endl;
		ShowList(Head->next);
	}
}

void DeleteNode(Node* Head, int ItemInfo, bool Type)
{
	if (Type) //ɾ����Iteminfo�����
	{
		Node* p = Head, * s;
		for (int i = 0; i < ItemInfo - 1; i++)
			p = p->next;
		s = p->next;
		p->next = s->next;
		delete s;
		Head->data--;
	}
	else    //ɾ��ֵΪIteminfo�Ľ��
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

//ɾ���������i������ֵΪval�Ľ��
//bool�����TypeΪtrueʱ��������Ϊɾ����i�����
//Ϊfalseʱ��������Ϊɾ��ֵΪval�Ľ��
//ͷ��㲻����ɾ��

int main()
{
	Node* List1 = new Node;
	Node* List2 = new Node;
	CreateList(List1);
	DeleteNode(List1, 1, true);
	cout << "List1:" << endl;
	ShowList(List1->next);//ͷ���洢���������������
	cout << "��������������������" << endl;//�ָ���
	CreateList(List2);
	DeleteNode(List2, 8, false);
	cout << "List2:" << endl;
	ShowList(List2->next);//ͷ���洢���������������
}