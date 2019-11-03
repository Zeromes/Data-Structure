struct DataType
{
	KeyType key;

	DataType(void){}
	DataType(KeyType k): key(k){}
	int operator ==(const DataType &a)
		{return key == a.key;}
	int operator !=(const DataType &a)
		{return key != a.key;}
};
