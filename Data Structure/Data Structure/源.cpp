#include<iostream>
using namespace std;

struct Graph8
{
	int data[8];
	int arcs[8][8];
};

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

void FirstAdj(int v,Graph8* G)
{
	for (int i = 0; i < 8; i++)
	{
		if (G->arcs[v - 1][i] == 1)
		{
			cout << "���Ϊ" << v << "�Ķ���ĵ�һ���ڽӶ���Ϊ��" << i + 1 << endl;
			break;
		}
		else continue;
	}
}

void NextAdj(int v, int w, Graph8* G)
{
	bool found = false;
	if (G->arcs[v][w] == 0)
	{
		cout << "w����v���ڽӶ��㣡";
	}
	else
	{
		for (int i = w; i < 8; i++)
		{
			if (G->arcs[v - 1][i] == 1)
			{
				cout << "����" << v << "�������ڽӶ���" << w << "�����һ���ڽӶ���Ϊ��" << i + 1;
				found = true;
				break;
			}
			else continue;
		}
		if (!found)
		{
			cout << "����" << v << "�������ڽӶ���" << w << "������һ���ڽӶ��㣡";
		}
	}
}

void DFS(int v, Graph8* G,bool visited[])
{
	cout << v << " ";
	visited[v] = true;
	for (int i = 0; i < 8; i++)
		if (G->arcs[v][i] == 1 && !visited[i])DFS(i, G, visited);
}

void BFS(int v, Graph8* G)
{

}

int main()
{
	Graph8* Graph = new Graph8;
	Initialze(Graph);
c:
	cout << "1.�ҵ����Ϊv�Ķ���ĵ�һ���ڽӶ���" << endl
		<< "2.�ҵ�v���������ڽӶ���w�����һ���ڽӶ���" << endl
		<< "3.����ͨͼ�Ӷ���v��ʼ����������ȷ���" << endl
		<< "4.����ͨͼ�Ӷ���v��ʼ���й�����ȷ���" << endl
		<< "��ѡ��Ҫ���еĲ�����";
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		cout << "������v��";
		int v;
		cin >> v;
		FirstAdj(v, Graph);
	case 2:
		int v, w;
		cout << "������v��";
		cin >> v;
		cout << "������w��";
		cin >> w;
		NextAdj(v, w, Graph);
	case 3:
		cout << "������v��";
		int v;
		cin >> v;
		bool visited[8];
		for (int i = 0; i < 8; i++)visited[i] = false;
		cout << v << " ";
		cout << "����˳��";
		DFS(v, Graph, visited);
	case 4:
		cout << "������v��";
		int v;
		cin >> v;
		BFS(v, Graph);
	default:
		cout << "�������" << endl;
		goto c;
	}
	return 0;
}