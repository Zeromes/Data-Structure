#include<iostream>
#include<string>
using namespace std;

struct TreeNode
{
	char data;
	TreeNode* LeftTree;
	TreeNode* RightTree;
	TreeNode(char x = '#') :data(x), LeftTree(NULL), RightTree(NULL) {};
};

void CreateTree(string Fstring, string Mstring, TreeNode*& Root)
{
	if (Mstring[0] == '#')
		return;
	else
	{
		Root = new TreeNode(Fstring[0]);
		string LeftMstring;
		LeftMstring.assign(Mstring, 0, Mstring.find(Fstring[0]));
		LeftMstring += '#';
		string RightMstring = Mstring;
		RightMstring.erase(0, Mstring.find(Fstring[0]) + 1);
		string LeftFstring;
		LeftFstring.assign(Fstring, 1, LeftMstring.length() - 1);
		LeftFstring += '#';
		string RightFstring;
		RightFstring.assign(Fstring, LeftMstring.length(), RightMstring.length());
		CreateTree(LeftFstring, LeftMstring, Root->LeftTree);
		CreateTree(RightFstring, RightMstring, Root->RightTree);
	}
}

void ShowTree(TreeNode* Root)
{
	if (Root == NULL)
		return;
	else
	{
		ShowTree(Root->LeftTree);
		ShowTree(Root->RightTree);
		cout << Root->data;
	}
}

int main()
{
	string Fstr, Mstr;
	cout << "请输入先根序列:";
	cin >> Fstr;
	cout << "请输入中根序列:";
	cin >> Mstr;
	Fstr = Fstr + "#";
	Mstr = Mstr + "#";
	TreeNode* Root;
	CreateTree(Fstr, Mstr, Root);
	cout << "生成树成功！该树的后根序列为:";
	ShowTree(Root);
}