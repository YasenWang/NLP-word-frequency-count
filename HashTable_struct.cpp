#define Datatype int
#define M 30

typedef struct HashNode
{
	Datatype data;
	int isNULL;			//标志该位置是否被填充
}HashTable;

HashTable hashtable[M];

void initHashTable()
{
	int i;
	for (i = 0; i < M; i++)
	{
		hashtable[i].isNULL = 1;	//初始状态为空
	}
}

int getHashAddress(Datatype key)	//Hash 函数
{
	return key % 29;
}

int insert(Datatype key)			//向Hash表中插入元素
{
	int address = getHashAddress(key);
	if (hashtable[address].isNULL == 1)	//无冲突
	{
		hashtable[address].data = key;
		hashtable[address].isNULL = 0;
	}
	else
	{
		while (hashtable[address].isNULL == 0 && address < M)
		{
			address++;
		}
		if (address == M)
			return -1;
		hashtable[address].data = key;
		hashtable[address].isNULL = 0;
	}
	return 0;
}

int find(Datatype key)					//查找
{
	int address = getHashAddress(key);
	while (!(hashtable[address].isNULL == 0 && hashtable[address].data == key&&address < M))
		address++;
	if (address == M)
		address = -1;
	return address;
}

int main(int argc, char *argv[])
{
	int key[] = { 123,456,7000,8,1,13,11,555,425,393,212,546,2,99,196 };
	int i;
	initHashTable();
	for (i = 0; i < 15; i++)
	{
		insert(key[i]);
	}
	for (i = 0; i < 15; i++)
	{
		int address;
		address = find(key[i]);
		printf("%d %d\n", key[i], address);
	}
	system("pause");
	return 0;
}
