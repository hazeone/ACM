#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
long long t[200000];
int n,m,id[200000],tot;
long long a[200000],b[200000][2];
multiset<long long>s;
struct point 
{
	long long num;
	int pos;
}c[2000000];
bool cmp(point x,point y)
{
	return x.num<y.num;
}
int lowbit(int x)
{
	return x&-x;
}
void add(int x,long long y)
{
	for(;x<=tot;x+=lowbit(x))
	t[x]+=y;
}
long long getsum(int x)
{
	long long re=0
	for(;x;x-=lowbit(x))
	re+=t[x];
	return re;
}
void work()
{
	long long sum=0;
	
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s.insert(a[i]);
		c[i].num=a[i];
		c[i].pos=i;
	}
	tot=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&b[i][0],&b[i][1]);
		c[++tot].num=b[i][1];
		c[tot].pos=n+i;
	}
	sort(c+1,c+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	id[c[i].pos]=i;
	for(int i=1;i<=n;i++)
	{
		add(id[i],c[id[i]].num);
	}
	work();
	for(int i=n+1;i<=m;i++)
	{
		add(id[i],c[id[i]].num);s.insert(c[id[i]].num);
		int x=c[id[i]].pos-n;
		add(id[b[x][0]],-c[id[b[x][0]]].num);
		s.eraser(s.find(c[id[b[x][0]].num));
		id[b[x][0]]=id[i];
		work();
	}
	return 0;
}
