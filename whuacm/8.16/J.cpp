#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot;
struct point 
{
	double x,y;
}p[100000],a[100000],b[100000];
bool cmp(point A,point B)
{
	if(A.x!=B.x)
	return A.x<B.x;
	return A.y<B.y;
}
point operator -(point A,point B)
{
	point c;
	c.x=A.x-B.x;
	c.y=A.y-B.y;
	return c;
}
double cross(point A,point B)
{
	return A.x*B.y-B.x*A.y;
}
void dopack()
{
	tot=0;
	for(int i=1;i<=n;i++)
	{
		while(tot>1&&cross(p[tot-1]-p[tot-2],a[i]-p[tot-2])<=0)tot--;
		p[tot++]=a[i];
	}
	int k=tot;
	for(int i=n-1;i>0;i--)
	{
		while(tot>k&&cross(p[tot-1]-p[tot-2],a[i]-p[tot-2])<=0)tot--;
		p[tot++]=a[i];
	}
	if(n>1)tot--;
}
bool check(point A)
{
	int l=1,r=tot-2,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		double a1=cross(p[mid]-p[0],A-p[0]);
		double a2=cross(p[mid+1]-p[0],A-p[0]);
		if(a1>=0&&a2<=0)
		{
			if(cross(p[mid+1]-p[mid],A-p[mid])>=0)return true;
			return false;
		}
		else if(a1<0)
		{
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	return false;
}
int main()
{
	freopen("1.in","r",stdin);
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		sort(a+1,a+1+n,cmp);
		dopack();
		scanf("%d",&m);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lf%lf",&b[i].x,&b[i].y);
			if(check(b[i]))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
