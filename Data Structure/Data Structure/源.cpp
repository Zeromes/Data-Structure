#include<iostream>
using namespace std;

struct Graph8
{
	int data[8];
	int arcs[8][8];
};

struct Queue
{
	int* base;
	int front;
	int rear;
};

void InitQueue(Queue& Q)
{
	Q.base = new int[10];
	Q.front = Q.rear = 0;
}

void EnQueue(Queue& Q, int e)
{
	if ((Q.rear + 1) % 10 == Q.front)
	{
		cout << "��������" << endl;
		return;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 10;
}

void DeQueue(Queue& Q, int& e)
{
	if (Q.rear == Q.front)
	{
		cout << "���пգ�" << endl;
		return;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % 10;
}

bool QueueEmpty(Queue& Q)
{
	if (Q.rear == Q.front)return true;
	else return false;
}

void Initialze(Graph8* G)
{
	for (int i = 0; i < 8; i++)
	{
		G->data[i] = i + 1;
	}
	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; k < 8; k++)
		{
			G->arcs[j][k] = 0;
		}
	}
	G->arcs[0][1] = 1;
	G->arcs[0][2] = 1;
	G->arcs[1][3] = 1;
	G->arcs[1][4] = 1;
	G->arcs[2][5] = 1;
	G->arcs[2][6] = 1;
	G->arcs[3][7] = 1;
	G->arcs[4][7] = 1;
	G->arcs[5][7] = 1;
	G->arcs[6][7] = 1;
	for (int j = 0; j < 7; j++)
	{
		for (int k = j + 1; k < 8; k++)
		{
			G->arcs[k][j] = G->arcs[j][k];
		}
	}
}

void ShowMatrix(Graph8* G)
{
	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; k < 8; k++)
		{
			cout << G->arcs[j][k] << " ";
		}
		cout << endl;
	}
}

int FirstAdj(int v,Graph8* G)
{
	for (int i = 0; i < 8; i++)
	{
		if (G->arcs[v - 1][i] == 1)
		{
			return i + 1;
			break;
		}
		else continue;
	}
}

int NextAdj(int v, int w, Graph8* G)
{
	bool found = false;
	if (G->arcs[v - 1][w - 1] == 0)
	{
		return -1;
	}
	else
	{
		for (int i = w; i < 8; i++)
		{
			if (G->arcs[v - 1][i] == 1)
			{
				return i + 1;
				found = true;
				break;
			}
			else continue;
		}
		if (!found)
		{
			return -2;
		}
	}
}

void DFS(int v, Graph8* G,bool visited[])
{
	cout << v << " ";
	visited[v - 1] = true;
	for (int i = 0; i < 8; i++)
		if (G->arcs[v - 1][i] == 1 && !visited[i])DFS(i + 1, G, visited);
}

void BFS(int v, Graph8* G, bool visited[])
{
	cout << v << " ";
	visited[v - 1] = true;
	Queue Q;
	InitQueue(Q);
	EnQueue(Q, v - 1);
	int u;
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, u);
		for (int w = FirstAdj(u, G); w >= 0; w = NextAdj(u, w, G))
		{
			if (!visited[w])
			{
				cout << w + 1 << " ";
				visited[w] = true;
				EnQueue(Q, w);
			}
		}
	}
}

int main()
{
	Graph8* Graph = new Graph8;
	Initialze(Graph);
c:
	cout << "1.�ҵ����Ϊv�Ķ���ĵ�һ���ڽӶ���" << endl
		<< "2.�ҵ�v���������ڽӶ���w�����һ���ڽӶ���" << endl
		<< "3.����ͨͼ�Ӷ���v��ʼ����������ȷ���" << endl
		<< "4.����ͨͼ�Ӷ���v��ʼ���й�����ȷ���" << endl << endl
		<< "��ѡ��Ҫ���еĲ�����";
	int c;
	cin >> c;
	cout << endl;
	switch (c)
	{
	case 1:
	{
		cout << "������v��";
		int v;
		cin >> v;
		cout << "���Ϊ" << v << "�Ķ���ĵ�һ���ڽӶ���Ϊ��" << FirstAdj(v, Graph) << endl;
		break;
	}
	case 2:
	{
		int v, w;
		cout << "������v��";
		cin >> v;
		cout << "������w��";
		cin >> w;
		if (NextAdj(v, w, Graph) == -1)cout << "w����v���ڽӶ��㣡";
		else if(NextAdj(v, w, Graph) == -2)cout << "����" << v << "�������ڽӶ���" << w << "������һ���ڽӶ��㣡";
		else cout << "����" << v << "�������ڽӶ���" << w << "�����һ���ڽӶ���Ϊ��" << NextAdj(v, w, Graph);
		break;
	}
	case 3:
	{
		cout << "������v��";
		int v;
		cin >> v;
		bool visited[8];
		for (int i = 0; i < 8; i++)visited[i] = false;
		cout << "����˳��";
		DFS(v, Graph, visited);
		break;
	}
	case 4:
	{
		cout << "������v��";
		int v;
		cin >> v;
		bool visited[8];
		for (int i = 0; i < 8; i++)visited[i] = false;
		cout << "����˳��";
		BFS(v, Graph,visited);
		break;
	}
	default:
	{
		cout << "�������" << endl;
		goto c;
	}
	}
	return 0;
}