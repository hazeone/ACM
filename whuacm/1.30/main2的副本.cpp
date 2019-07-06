#include<bits/stdc++.h>
using namespace std;
const int M = 100010;
const double eps = 1e-10;
struct point
{
	double x,y;
	point();
	point(double x1,double y1)
	{
		x=x1;
		y=y1;
	}
}a[M];
struct Line
{
	point st,ed;
}c[M];
double ans;
int n;
int flag[M],b[M];
int dcmp(double x)
{
	if(fabs(x)<eps)
		return 0;
	return x<0?-1:1;
}
point operator - (const point &x,const point &y)
{
	return point(x.x-y.x,x.y-y.y);
}
double cross(const point &x,const point &y)
{
	return x.x*y.y-x.y*y.x;
}
bool judge(point a1,point a2,point b1,point b2)
{
	double c1= cross(a2-a1,b1-a1),c2=cross(a2-a1,b2-a1),
			c3=cross(b2-b1,a1-b1),c4=cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
double get_length(const point &x,const point &y)
{
	point hh=x-y;
	return sqrt(hh.x*hh.x+hh.y*hh.y);
}
double work()
{
	double sum=0;
	for(int i=1;i<n;i++)
		sum+=get_length(a[b[i]],a[b[i+1]]);
	sum+=get_length(a[b[n]],a[b[1]]);
	return sum;
}
void deal()
{
	for(int i=1;i<n;i++)
	{
		c[i].st=a[b[i]];
		c[i].ed=a[b[i+1]];
	}
	c[n].st=a[b[n]];
	c[n].ed=a[b[1]];
	bool flag=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			flag=max(flag,judge(c[i].st,c[i].ed,c[j].st,c[j].ed));
	if(!flag)
		ans=max(ans,work());
	return ;
}
void dfs(int x)
{
	if(x==n+1)
	{
		deal();
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			b[x]=i;
			flag[i]=1;
			dfs(x+1);
			flag[i]=0;
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	dfs(1);
	printf("%.6lf\n",ans);
	return 0;
}
