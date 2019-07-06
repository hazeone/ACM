#include<cstdio>
#include<iostream>
using namespace std;
double sum=0;
int main()
{
	freopen("1.out","w",stdout);
	for(int i=1;i<=125000;i++)
	{
		double k=i;
		sum=sum+1.0/k/k;
		printf("%.5lf\n",sum);
	}
	return 0;
}

