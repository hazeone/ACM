#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
double r[1024][1024],dis[1024][1024];
int n,s,t,q[1000000],v[100000];
double w;
struct point 
{
	double x,y;
}a[100000];
double getdis(int i,int j)
{
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
double MIN(double X,double Y)
{
	return X>Y?Y:X;
}
double MAX(double X,double Y)
{
	return X>Y?X:Y;
}
void spfa()
{
	int head,tail;
	for(int k=s;k<=t;k++)
	{
		for(int i=1;i<=t;i++)
		{
			dis[k][i]=1000000009;
			v[i]=0;
		}
		head=0;tail=1;
		v[k]=1;
		q[1]=k;
		dis[k][k]=0;
		while(head!=tail)
		{
			head=head%t+1;
			int nod=q[head];
			v[nod]=0;
			for(int i=1;i<=t;i++)
			{
				if(i!=nod)
				{
					if(dis[k][i]>MAX(dis[k][nod],r[nod][i]))
					{
						dis[k][i]=MAX(dis[k][nod],r[nod][i]);
						if(!v[i])
						{
							tail=tail%t+1;
							q[tail]=i;
							v[i]=1;
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("froggy.in","r",stdin);
	freopen("froggy.out","w",stdout);
	cin>>w>>n;
	s=n+1;t=n+2;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
		r[i][s]=r[s][i]=a[i].x;
		r[i][t]=r[t][i]=w-a[i].x;
	}
	r[s][t]=r[t][s]=w;
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	r[i][j]=r[j][i]=getdis(i,j);
	a[t].x=w;
	spfa();
	double ans=dis[s][t],ax=1,ay=1;
	for(int i=1;i<=t;i++)
	for(int j=1;j<=t;j++)
	{
		if(i==j)continue;
		double tmp=MAX(MAX(dis[s][i],dis[t][j]),r[i][j]/2.0);
		if(tmp<ans)
		{
			ans=tmp;
			ax=(a[i].x+a[j].x)/2.0;
			if(i<=n&&j<=n)
			ay=(a[i].y+a[j].y)/2.0;
			else ay=a[i].y+a[j].y;
		}
	}
	printf("%.3lf %.3lf\n",ax,ay);
	return 0;
}
