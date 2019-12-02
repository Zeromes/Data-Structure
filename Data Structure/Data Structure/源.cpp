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
		cout << "队列满！" << endl;
		return;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % 10;
}

void DeQueue(Queue& Q, int& e)
{
	if (Q.rear == Q.front)
	{
		cout << "队列空！" << endl;
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
	cout << "1.找到编号为v的顶点的第一个邻接顶点" << endl
		<< "2.找到v的排在其邻接顶点w后的下一个邻接顶点" << endl
		<< "3.对连通图从顶点v开始进行深度优先访问" << endl
		<< "4.对连通图从顶点v开始进行广度优先访问" << endl << endl
		<< "请选择要进行的操作：";
	int c;
	cin >> c;
	cout << endl;
	switch (c)
	{
	case 1:
	{
		cout << "请输入v：";
		int v;
		cin >> v;
		cout << "编号为" << v << "的顶点的第一个邻接顶点为：" << FirstAdj(v, Graph) << endl;
		break;
	}
	case 2:
	{
		int v, w;
		cout << "请输入v：";
		cin >> v;
		cout << "请输入w：";
		cin >> w;
		if (NextAdj(v, w, Graph) == -1)cout << "w并非v的邻接顶点！";
		else if(NextAdj(v, w, Graph) == -2)cout << "顶点" << v << "排在其邻接顶点" << w << "后无下一个邻接顶点！";
		else cout << "顶点" << v << "排在其邻接顶点" << w << "后的下一个邻接顶点为：" << NextAdj(v, w, Graph);
		break;
	}
	case 3:
	{
		cout << "请输入v：";
		int v;
		cin >> v;
		bool visited[8];
		for (int i = 0; i < 8; i++)visited[i] = false;
		cout << "访问顺序：";
		DFS(v, Graph, visited);
		break;
	}
	case 4:
	{
		cout << "请输入v：";
		int v;
		cin >> v;
		bool visited[8];
		for (int i = 0; i < 8; i++)visited[i] = false;
		cout << "访问顺序：";
		BFS(v, Graph,visited);
		break;
	}
	default:
	{
		cout << "输入错误！" << endl;
		goto c;
	}
	}
	return 0;
}