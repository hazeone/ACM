#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,m,qq;
int g[1000000],g2[1000000],pre[1000000],q[1000002],val[1000000],vis[1000000],used[1000000],d[200000],v[2000000];
int dis[106][100003];
int tot,tot2;
int inf=1e9+7;
struct point 
{
	int next,to,w,from;
}e[1000000],h[1000000],ee[1000000];
int find(int x)
{
	return x==pre[x]?x:(pre[x]=find(pre[x]));
}
void add(int x,int y,int z)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	e[tot].w=z;
	g[x]=tot;
}
void add2(int x,int y)
{
	h[++tot2].to=y;
	h[tot2].next=g2[x];
	h[tot2].from=x;
	h[tot2].w=inf;
	g2[x]=tot2;
}
void spfa(int sum,int begin)
{
	int head=0,tail=1;
	q[tail]=begin;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		dis[sum][i]=inf;
	}
	vis[begin]=1;
	dis[sum][begin]=0;
	while(head<tail)
	{
		head=head%n+1;
		int x=q[head];
		vis[x]=0;
		for(int tmp=g[x];tmp;tmp=e[tmp].next)
		{
			if(dis[sum][e[tmp].to]>dis[sum][x]+e[tmp].w)
			{
				dis[sum][e[tmp].to]=dis[sum][x]+e[tmp].w;
				if(!vis[e[tmp].to])
				{
					vis[e[tmp].to]=1;
					tail=tail%n+1;
					q[tail]=e[tmp].to;
				}
			}
		}
    }
  //  cout<<sum<<": "<<endl;
   // for(int i=1;i<=n;i++)
  //  {
//		cout<<i<<": "<<dis[sum][i]<<endl;
//	}
}
void lca(int nod)
{
	 pre[nod]=nod;
	 v[nod]=1;
     for(int temp=g[nod];temp;temp=e[temp].next)
     {
             if(v[e[temp].to])continue;
             lca(e[temp].to);
             pre[find(e[temp].to)]=find(nod);
             val[find(nod)]=nod; 
     }
     vis[nod]=1;
     for(int temp=g2[nod];temp;temp=h[temp].next)
     {
             if(vis[h[temp].to])
             {
                                h[temp].w=dis[0][nod]+dis[0][h[temp].to]-2*dis[0][val[find(h[temp].to)]];
             }
     }
}
void clr()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		g[i]=g2[i]=0;
		pre[i]=i;
		v[i]=0;
	}
	tot=tot2=0;
	for(int i=1;i<=m;i++)
	{
		used[i]=0;
	}
}
int main()
{
	freopen("C.in","r",stdin);
	cin>>T;
	for(int p=1;p<=T;p++)
	{
		printf("Case %d:\n",p);
		scanf("%d%d%d",&n,&m,&qq);
		clr();
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			int t1=find(x),t2=find(y);
			ee[i].from=x;
			ee[i].to=y;
			ee[i].w=z;
			if(t1!=t2)
			{
			//	cout<<x<<" "<<y<<endl;
				pre[t1]=t2;
				used[i]=1;
				add(x,y,z);
				add(y,x,z);
			}
		}
		int sum=0,begin=1;
		spfa(sum,begin);
		for(int i=1;i<=qq;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add2(x,y);
			add2(y,x);
		}
		for(int i=1;i<=n;i++)
		{
			v[i]=vis[i]=val[i]=0;
		}
		lca(1);
		for(int i=1;i<=m;i++)
		{
			if(!used[i])
			{
				add(ee[i].from,ee[i].to,ee[i].w);
				add(ee[i].to,ee[i].from,ee[i].w);
			}
		}
		//cout<<"!!!!!!!!!!!!!!!!"<<endl;
		for(int i=1;i<=m;i++)
		{
			if(!used[i])
			{
				sum++;
				spfa(sum,ee[i].from);
				sum++;
				spfa(sum,ee[i].to);
			}
		}
		for(int i=1;i<=qq*2;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				h[i].w=min(h[i].w,dis[j][h[i].to]+dis[j][h[i].from]);
			}
		}
		for(int i=1;i<=qq;i++)
		printf("%d\n",min(h[i*2-1].w,h[i*2].w));
	}
	return 0;
}
