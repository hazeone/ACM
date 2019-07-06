#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,m;
long long ans,sum[100000];
struct point
{
	int to,next;
}e[100000];
int g[10000],tot;
void add(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
	//cout<<1<<endl;
}
int main()
{
	freopen("B.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		sum[j]=0;
		for(int temp=g[i];temp;temp=e[temp].next)
		{
			int x=e[temp].to;
			for(int tmp=g[x];tmp;tmp=e[tmp].next)
			sum[e[tmp].to]++;
		}
		for(int j=1;j<=n;j++)
		{//cout<<1<<endl;
			if(j!=i)
			{
				ans+=sum[j]*(sum[j]-1)/2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
