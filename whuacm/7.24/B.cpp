#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int pre[1000000],g[1000000],dis[1000000],rk[1000000],v[1000000],dis2[1000000];
int m,n,q,tot,max1,max2,node;
struct point
{
	int to,next;
}e[1000000];
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
}
void dfs(int x,int anc)
{
	pre[x]=anc;
	v[x]=1;
	for(int tmp=g[x];tmp;tmp=e[tmp].next)
	{
		if(!v[e[tmp].to])
		{
			dis[e[tmp].to]=dis[x]+1;
	    	dfs(e[tmp].to,anc);
		}
	}
	if(dis[x]>=max1)
	{max1=dis[x];node=x;}
	v[x]=0;
}
void dfs2(int x)
{
	v[x]=1;
	for(int tmp=g[x];tmp;tmp=e[tmp].next)
	{
		if(!v[e[tmp].to])
		{
			dis2[e[tmp].to]=dis2[x]+1;
			dfs2(e[tmp].to);
		}
	}
	if(dis2[x]>=max2)max2=dis2[x];
}
int find(int x)
{
	return x==pre[x]?x:(pre[x]=find(pre[x]));
}
int main()
{
	freopen("B.in","r",stdin);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			max1=max2=0;
			dfs(i,i);
			//cout<<i<<" "<<max1<<" "<<node<<" ";
			dfs2(node);
			//cout<<max2<<endl;
			rk[i]=max2;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&x);
			y=rk[find(x)];
			printf("%d\n",y);
		}
		else
		{
			scanf("%d%d",&x,&y);
			int s=find(x),t=find(y);
			if(s!=t)
			{
				pre[s]=t;
				int mi=rk[s]<rk[t]?rk[s]:rk[t],ma=rk[s]>rk[t]?rk[s]:rk[t],tmp=1;
				if(mi&1)tmp+=mi/2+1;
				else tmp+=mi/2;
				if(ma&1)tmp+=ma/2+1;
				else tmp+=ma/2;
				rk[t]=ma>tmp?ma:tmp;
			}
		}
	}
	return 0;
}
