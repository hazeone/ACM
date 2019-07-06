#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long sa,sb;
struct point
{
	int pos,s;
}a[100000],b[100000];
bool cmp1(point x,point y)
{
	return x.s<y.s;
}
bool cmp2(point x,point y)
{
	return x.s>y.s;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].pos=i;
		sa+=a[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].s;
		b[i].pos=i;
		sb+=b[i].s;
	}
	if(sa<sb)
	{
		sort(a+1,a+1+n,cmp2);
		sort(b+1,b+1+n,cmp1);
	}
	else
	{
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp2);
	}
	for(int i=1;i<=n;i++)
	printf("%d %d\n",a[i].pos,b[i].pos);
	return 0;
}
