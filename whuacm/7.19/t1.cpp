#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int pre[200000],n,m,g[3000000],tot,v[200000],used[2000000],siz[200000];
struct point
{
	int to,next,from,w;
}e[300000],h[300000];
int T;
long long ans1;
void clr()
{
	ans1=tot=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;v[i]=0;siz[i]=0;
		e[i].to=e[i].next=e[i].from=h[i].to=h[i].next=h[i].to=0;
	}
	for(int i=0;i<=2000000;i++)
	{
		g[i]=0;used[i]=0;
	}
}
bool cmp(point x,point y)
{
	return x.w<y.w;
}
void add(int a,int b,int c)
{
	tot++;
	e[tot].next=g[a];
	e[tot].w=c;
	e[tot].to=b;
	e[tot].from=a;
	g[a]=tot;
}
int find(int x)
{
	return x==pre[x]?x:(pre[x]=find(pre[x]));
}
void dfs1(int x)
{
	siz[x]++;
	v[x]=1;
	for(int tmp=g[x];tmp;tmp=e[tmp].next)
	{
		if(!v[e[tmp].to])
		{
			dfs1(e[tmp].to);
			siz[x]+=siz[e[tmp].to];
			used[tmp]=1;
		}		
	}
}
int main()
{
	freopen("t1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		clr();
		for(int i=0;i<m;i++)
		{
			cin>>h[i].from>>h[i].to>>h[i].w;
		}
		sort(h,h+m,cmp);
		for(int i=0;i<m;i++)
		{
			int x=find(h[i].from),y=find(h[i].to);
			if(x==y)continue;
			pre[x]=y;
			add(h[i].from,h[i].to,h[i].w);
			add(h[i].to,h[i].from,h[i].w);
			ans1+=h[i].w;
		}
		dfs1(1);
		cout<<ans1<<" ";
		long double sum2=n*(n-1)/2;
		long double sum=0;
		for(int i=1;i<=tot;i++)
		{
			if(used[i])
			{
				int a=siz[e[i].to],b=siz[e[i].from];
				int size=a<b?a:b;
				sum+=size*(n-size)*e[i].w/sum2;
			}
		}
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
	}
}
