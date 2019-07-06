#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,q,tot;
struct point
{
	int v,x,y,r,d;
}e[1000005];
void add(int i,int j,int vv)
{
	int now=0;
	if(i>e[now].x)
	{
		if(!e[now].x)
		{
			e[++tot].v=vv;
			e[tot].x=i;
			e[tot].y=j;
			e[now].x=tot;
		}
	}
}
int main()
{
	/*cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int vv;
		cin>>vv;
		add(i,j,vv);
	}*/
	int y1;
	y1=3;
	cout<<y1<<endl;
	return 0;
}
