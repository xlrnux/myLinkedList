

#include <cstdio>
#include "list.h"
//#include<list>
using namespace std;
int main()
{
	list<int> nlist;
	for (int i = 0; i < 10; i++)
	{
        nlist.push_back(i);
	}

    nlist.insert(nlist.begin(), 5);
	printf(":: 일반 반복문으로 출력 ::\n");
	for (list<int>::iterator iter = nlist.begin(); iter != nlist.end(); iter++)
	{
		printf("%d\n",*iter );
	}

	printf("\n\n\n:: 범위 기반 반복문으로 출력 ::\n");
    for (auto iter : nlist)
	{
		printf("%d\n", iter);
	}
	printf("Size = %d\n", nlist.size());
	printf("Empty = %d\n", nlist.empty());
}