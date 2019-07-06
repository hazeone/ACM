#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	int pos,num;
}a[200000];
int n,k;
long long t[200000],c[200000];
bool cmp(point x,point y)
{
	return x.num<y.num;
}
int lowbit(int x)
{
	return x&-x;
}
long long getsum(int x)
{
	long long re=0;
	for(;x;x-=lowbit(x))
	{
		re+=t[x];
	}
	return re;
}
void add(int x)
{
	for(;x<=n;x+=lowbit(x))
	{
		t[x]++;
	}
}
void clr()
{
	for(int i=1;i<=100000;i++)c[i]=t[i]=0;
}
int main()
{
	freopen("A.in","r",stdin);
	while(cin>>n>>k)
	{
		clr();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].num;
			a[i].pos=i;
		}
		sort(a+1,a+1+n,cmp);
		int last=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i].num==a[last].num)
			{
				c[a[i].pos]=last;
			}
			else
			{
				last=i;
				c[a[i].pos]=last;
			}
		}
		//for(int i=1;i<=n;i++)
		//cout<<c[i]<<" ";
		long long ans=0;
		for(int i=n;i>0;i--)
		{
			ans+=getsum(c[i]-1);
			add(c[i]);
		}
		cout<<max(ans-k,(long long)0)<<endl;
	}
	return 0;
}
