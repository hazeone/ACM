#include<bits/stdc++.h>
using namespace std;
const int N=210000;
struct point 
{
	int to,next;
}e[N];
int tot,g[N],n,T,f[N];
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
}
void dfs1(int x,int pre,int now)
{
	int cnt=0;
	if(now==0)
	{
		for(int tmp=g[x];tmp;tmp=e[tmp].next)
		{
			int y=e[tmp].to;
			if(y==pre)continue;
			cnt++;
			dfs1(y,x,now^1);
			f[x]+=f[y];
		}
	}
	else
	{
		f[x]=n;
		for(int tmp=g[x];tmp;tmp=e[tmp].next)
		{
			int y=e[tmp].to;
			if(y==pre)continue;
			cnt++;
			dfs1(y,x,now^1);
			f[x]=min(f[x],f[y]);
		}
	}
	if(cnt==0)
	f[x]=1;
}
void clear()
{
	tot=0;
	for(int i=0;i<=n;i++)g[i]=f[i]=0;
}
int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		clear();
		for(int i=1; i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs1(1,0,1);
		printf("%d\n",f[1]);
	}
	return 0;
}

