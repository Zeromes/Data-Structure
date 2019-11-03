#include <iostream.h>
typedef int keytype;
struct datatype
{
	keytype key;
	datatype(void){}
	datatype(keytype k): key(k){}
	int operator ==(datatype &a)
		{return key == a.key;}
	int operator !=(datatype &a)
		{return key != a.key;}
};

void main(void)
{
	datatype a = 3, b = 6;
	if(a == b) cout << "a == b";
	else cout << "a != b";
}