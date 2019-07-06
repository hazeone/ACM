#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tot;
//#define eps 1e-10;
#define LL long long
struct point
{
    LL x,y;
    int p;
}p[200005],a[200005],b[200005];
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
LL cross(point A,point B)
{
    return A.x*B.y-B.x*A.y;
}
void dopack()
{
    tot=1;
    p[0]=a[n];
    int k=tot;
    for(int i=n-1;i>0;i--)
    {
        while(tot>k&&cross(p[tot-1]-p[tot-2],a[i]-p[tot-2])<0&&(cross(p[tot-1]-p[tot-2],a[i]-p[tot-2])==0&&a[i].p<p[tot-1].p))tot--;
        p[tot++]=a[i];
    }
    for(int i=tot-1;i>=0;i--)
    {
		if(i>0)
		printf("%d ",p[i].p);
		else printf("%d\n",p[i].p);
	}
}
int main()
{
	int cas;
	while(cin>>cas)
	{
    while(cas--)
    {
		scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].x,&a[i].y);
            a[i].p=i;
        }
        sort(a+1,a+1+n,cmp);
        dopack();
    }
}
    return 0;
}
