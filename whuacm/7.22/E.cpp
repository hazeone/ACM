#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[10000],b[10000],tot,g[200001],ans,pre[200000];
bool v[200000];
struct edge
{
	int to,next;
}e[200001];
void add(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
}
bool find(int nod)
{
	int x;
	for(int temp=g[nod];temp;temp=e[temp].next)
	{
		x=e[temp].to;
		if(v[x]==false)
		{
			v[x]=true;
			if(pre[x]==-1||find(pre[x])==true)
			{
				pre[x]=nod;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("E.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]-b[j]==-1||a[i]-b[j]==0||a[i]-b[j]==1)
			{
				add(i,j+100);
				add(j+100,i);
			}
		}
	}
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
	{
		memset(v,false,sizeof(v));
		if(find(i))ans++;
	}
	cout<<ans<<endl;
	return 0;
}
