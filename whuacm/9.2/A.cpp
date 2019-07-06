#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define inf 1000000009
using namespace std;
int S,T;long long ans;
int n,m,K,cnt=1;
long long dis[805][805],d[805];
int q[100005],g[805];
bool inq[805];
struct point{int to,next,v,c;}e[1000005];
void clr()
{
	cnt=1;
	ans=0;
	memset(d,0,sizeof(d));
	memset(g,0,sizeof(g));
}
void insert(int u,int v,int w,int c)
{
	e[++cnt].to=v;
	e[cnt].next=g[u];g[u]=cnt;e[cnt].v=w;e[cnt].c=c;
	e[++cnt].to=u;
	e[cnt].next=g[v];g[v]=cnt;e[cnt].v=0;e[cnt].c=-c;
}
void floyd()
{
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if((k<=i||k<=j)&&dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}
bool spfa()
{
	memset(inq,0,sizeof(inq));
	int head=0,tail=1;
	for(int i=0;i<=T;i++)d[i]=inf;
	q[0]=T;d[T]=0;inq[T]=1;
	while(head!=tail)
	{
		int now=q[head];head++;
		for(int i=g[now];i;i=e[i].next)
			if(e[i^1].v&&d[now]-e[i].c<d[e[i].to])
			{
				d[e[i].to]=d[now]-e[i].c;
				if(!inq[e[i].to])
				{
					inq[e[i].to]=1;q[tail++]=e[i].to;
				}
			}
		inq[now]=0;
	}
	return d[S]!=inf;
}

void build()
{
	for(int i=1;i<=n;i++)
	{
		insert(S,i+n+1,1,0);
		insert(i,T,1,0);
	}
	insert(S,n+1,K,0);
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dis[i][j]!=inf)insert(i+n+1,j,1,dis[i][j]);}
int dfs(int x,int f)
{
	inq[x]=1;if(x==T)return f;
	int used=0,w;
	for(int i=g[x];i;i=e[i].next)
		if(!inq[e[i].to]&&e[i].v&&d[x]-e[i].c==d[e[i].to])
		{
			w=f-used;
			w=dfs(e[i].to,min(e[i].v,w));
			ans+=w*e[i].c;
			e[i].v-=w;e[i^1].v+=w;
			used+=w;if(used==f)return f;
		}
	return used;
}
void zkw()
{
	while(spfa())
	{
		inq[T]=1;
		while(inq[T]){memset(inq,0,sizeof(inq));dfs(S,inf);}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	while(~scanf("%d%d",&n,&K))
	{
		m=0;
		S=2*n+2,T=S+1;
		clr();
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if(i!=j)dis[i][j]=inf;
				else dis[i][j]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i;j++)
			{
				cin>>dis[i][i+j+1];
				dis[j+i+1][i]=dis[i][i+j+1];
				m++;
			}
		}
		floyd();
		build();
		zkw();
		printf("%lld\n",ans);
    }
	return 0;
}
