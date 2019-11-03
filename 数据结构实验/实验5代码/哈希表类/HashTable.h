enum KindOfItem {Empty, Active, Deleted};

struct HashItem
{
	DataType data;
	KindOfItem info;

	HashItem(KindOfItem i = Empty): info(i){}
	HashItem(const DataType &D, KindOfItem i = Empty): data(D), info(i){}
	int operator ==(HashItem &a)
		{return data == a.data;}
	int operator !=(HashItem &a)
		{return data != a.data;}
};

class HashTable
{
private:
	HashItem *ht;										//哈希表数组
	int TableSize;									//哈希表的长度（即m）
	int currentSize;								//当前的表项个数
public:
	HashTable(int m);										//构造函数
	~HashTable(void)										//析构函数
		{delete []ht;}

	int Find(const DataType &x)const;						//查找
	int Insert(const DataType &x);							//插入
	int Delete(const DataType &x);							//删除

	int IsIn(const DataType &x)								//是否已存在
		{int i = Find(x); return i >= 0 ? 1: 0;}
	DataType GetValue(int i)const							//取数据元素
		{return ht[i].data;}
};

//哈希表类实现
HashTable::HashTable(int m)									//构造函数
{
	TableSize = m;										//置哈希表长度
	ht = new HashItem[TableSize];						//申请动态数组空间
	currentSize = 0;									//置初始的当前表项个数
}

int HashTable::Find(const DataType &x)const						//查找
{

  //输入你自己编写的程序
}

int HashTable::Insert(const DataType &x)
{
	int i = Find(x); 							//调用Find(x)

	if(i > 0) return 0;							//数据元素x已经存在
	else if(i != -TableSize)		//数据元素x不存在且哈希表未满
	{
		ht[-i].data = x;						//数据元素赋值
		ht[-i].info = Active;					//置活动标记
		currentSize++;							//当前表项个数加1
		return 1;								//返回插入成功状态
	}
	else return 0;								//返回插入失败状态
}

int HashTable::Delete(const DataType &x)					//删除
{
	int i = Find(x); 							//调用Find(x)

	if(i >= 0)
	{
		ht[i].info = Deleted;					//置删除标记
		currentSize--;							//当前表项个数减1
		return 1;								//返回删除成功状态
	}
	else return 0;								//返回删除失败状态
}
