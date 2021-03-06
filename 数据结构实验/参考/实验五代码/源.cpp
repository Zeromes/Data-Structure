#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

struct subdata
{
	string ip;
	int frequency;
};

struct list
{
	subdata ele;
	list* next;
	list() { next = NULL; };
};

long long GetFileSize(const string& file_name) 
{
	ifstream in(file_name.c_str());
	in.seekg(0, ios::end);
	long long size = in.tellg();
	in.close();
	return size; //单位是：byte
}

void generate(const string& fileName, long long size)
{
	ofstream File;
	File.open(fileName, ios::out);
	srand((unsigned)time(0));
	while (GetFileSize(fileName) < size)
	{
		for (int i = 0; i < 8; i++)File << hex << rand() % 16;
		File << "\n";
		cout << "生成进度：" << ((float)GetFileSize(fileName) / (float)size) * 100.0 << "%" << endl;
	}
	File.close();
	cout << "完成生成！" << endl;
}

void partition(const string& fileName)
{
	ifstream in;
	ofstream out;
	in.open(fileName, ios::in);
	system("mkdir sub");
	string t;
	string path = "./sub/";
	string name;
	int i = 0;
	while (in>>t)
	{
		i++;
		name = t.substr(0, 3);
		name += ".dat";
		out.open(path + name, ios::app);
		out << t << "\n";
		out.close();
		cout << "正在分析第" << i << "个" << endl;
	}
	in.close();
	cout << "拆分完成！" << endl;
}

void analyze()
{
	subdata* seq = new subdata[4096];
	int idx = 0;
	ifstream in;
	string path = "./sub/";
	string name;
	for (int i = 0; i < 4096; i++)
	{
		stringstream ss;
		ss << setw(3) << setfill('0') << hex << i;
		name = ss.str();
		name += ".dat";
		in.open(path + name, ios::in);
		if (!in)continue;
		else
		{
			cout << "正在分析" << name << endl;
			list* l = new list;
			string t;
			while (in >> t)
			{
				list* p = l;
				bool found = false;
				while (p->next != NULL)
				{
					if (p->ele.ip == t)
					{
						p->ele.frequency++;
						found = true;
						break;
					}
					p = p->next;
				}
				if (!found)
				{
					p->next = new list;
					p->next->ele.ip = t;
					p->next->ele.frequency = 1;
				}
			}
			list* p = l->next;
			int hfre = 0;
			list* h = l->next;
			while (p != NULL)
			{
				if (p->ele.frequency >= hfre)
				{
					h = p;
					hfre = p->ele.frequency;
				}
				p = p->next;
			}
			seq[idx] = h->ele;
			idx++;
			in.close();
		}
	}
	int h = 0, p;
	for (int i = 0; i < idx; i++)
	{
		if (seq[i].frequency >= h)
		{
			p = i;
			h = seq[i].frequency;
		}
	}
	int ip1, ip2, ip3, ip4;
	stringstream s1, s2, s3, s4;
	s1 << hex << seq[p].ip.substr(0, 2);
	s1 >> ip1;
	s2 << hex << seq[p].ip.substr(2, 2);
	s2 >> ip2;
	s3 << hex << seq[p].ip.substr(4, 2);
	s3 >> ip3;
	s4 << hex << seq[p].ip.substr(6, 2);
	s4 >> ip4;
	cout << "访问次数最多的IP是：" << ip1 << "." << ip2 << "." << ip3 << "." << ip4 << endl;
}

int main()
{
	string FileName = "data.dat";
	generate(FileName, 4294967296);
	partition(FileName);
	analyze();
	return 0;
}