#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
int n=10;
int dis[200000];
int a[200000];
int v[1000002];
long long mod=100;
int main()
{
	srand((unsigned)time(0));
	for(int i=1;i<=n;i++)
	{
		long long x=rand()%mod+1;
		//cout<<x<<endl;
		while(v[x])
		{
			x=rand()%mod+1;
		}
		v[x]=1;
		dis[i]=x;
	}//cout<<n<<endl;
	sort(dis+1,dis+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=rand()%2;
	}
	cout<<n;
	long long x=rand()%mod+1;
	while(v[x])
	{
		x=rand()%mod+1;
	}
	cout<<" "<<x<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",dis[i],a[i]);
	}
	return 0;
}
