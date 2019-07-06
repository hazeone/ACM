#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=100100;
int n,m;
struct point
{
	int l,r,ans,pos;
}q[N];
int a[N],sum;
int c1[N],c2[N],L[N],R[N];
inline int lowbit(int x)
{
	return x&(-x);
}
void add1(int x)
{
	for(;x<=n;x+=lowbit(x))
	{
		c1[x]+=1;
	}
}
void add2(int x)
{
	for(;x<=n;x+=lowbit(x))
	{
		c2[x]+=1;
	}
}
int  cal1(int x)
{
	int re=0;
	for(;x;x-=lowbit(x))
	{
		re-=c1[x];
	}
	return re;
}
int cal2(int x)
{
	int re=0;
	for(;x;x-=lowbit(x))
	{
		re-=c1[x];
	}
	return re;
}
void clr()
{
	memset(c1,0,sizeof(c1));
	memset(c1,0,sizeof(c2));
	sum=0;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		clr();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			if(L[a[i]]==0)
			{
				sum++;
				L[a[i]]=i;
			}
			R[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			add1(L[a[i]]);
			add2(R[a[i]]);
		}
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x++;
			y--;
			q[i].l=x;
			q[i].r=y;
			q[i].pos=i;
			if(x<=y)
			q[i].ans=sum-(cal2(y)-cal2(x-1)-(cal1(x-1)-cal2(x-1)));
			else q[i].ans=sum;
			printf("%d\n",q[i].ans);
		}
		//sort(a+1,a+1+m,cmp);
		//int L,R;
		//for(int i=1;i<=m;i++)
	}
	return 0;
}
