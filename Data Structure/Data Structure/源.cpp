#include<iostream>
#include<ctime>
#include<cmath>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct Node
{
	char data;
	Node* next;
	Node(char x = 0) :data(x), next(NULL) {}
};
class Queue
{
	Node* Front, * Rear;
	int size;
	int Flag;
public:
	Queue(int x = 0)
	{
		size = x;
		Flag = 0;
		if (x > 0)
		{
			Front = new Node;
			Rear = Front;
			Node* s = Rear;
			for (int i = 0; i < x - 1; i++)
			{
				s->next = new Node;
				s = s->next;
			}
			s->next = Front;
		}
		else abort();
	}
	bool EnQueue(char ch);
	bool DeQueue(char& ch);
};
bool Queue::EnQueue(char ch)
{
	if (Flag == 1)
		return false;
	else
	{
		Rear->data = ch;
		Rear = Rear->next;
		Flag = -1;
	}
	if (Rear == Front) Flag = 1;
	return true;
}
bool Queue::DeQueue(char& ch)
{
	if (Flag == 0)
		return false;
	else
	{
		Flag = -1;
		ch = Front->data;
		Front = Front->next;
	}
	if (Rear == Front) Flag = 0;
	return true;
}
int main()
{
	srand((unsigned)time(NULL));
	Queue a(5);
	char ch1, ch2;
	int Random = 1;
	while (1)
	{
		if (Random)
		{
			Sleep(500);
			if (_kbhit())
			{
				ch1 = _getwch();
				if (a.EnQueue(ch1) == false)
					cout << endl << "OverFlow" << endl;
			}
		}//进程1
		else
		{
			while (a.DeQueue(ch2))
				cout << ch2;
		}//进程2
		Random = rand() % 2;
	}
}