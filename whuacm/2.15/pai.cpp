#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n=100000,m=100000;
int main()
{
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++)
	{
		int x=rand()%i;
		if(!x)x++;
		printf("%d %d\n",i,x);
	}
	for(int i=1;i<=m;i++)
	{
		if(rand()&1)
		{
			printf("Q ");
			printf("%d %d\n",rand()%n+1,rand()%n+1);
		}
		else
		{
			printf("C ");
			printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%1000000000);
		}
	}
	return 0;
}
