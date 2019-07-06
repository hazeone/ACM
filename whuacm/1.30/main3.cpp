#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=1500;
int n;
int x,y;
int cnt=0;
int a[maxn][maxn];
int vis[maxn][maxn];
void change(int x,int y)
{
	if(vis[x][y])
		return;
	int tt=a[x][y];
	if(a[x][y+1]==tt&&a[x-1][y]==tt)
	{
		a[x][y]=-2;
		a[x][y+1]=-2;
		a[x-1][y]=-2;
		vis[x][y]=2;
		vis[x][y+1]=2;
		vis[x-1][y]=2;
		return;
	}
	if(a[x][y+1]==tt&&a[x+1][y]==tt)
	{
		a[x][y]=-4;
		a[x][y+1]=-4;
		a[x+1][y]=-4;
		vis[x][y]=4;
		vis[x][y+1]=4;
		vis[x+1][y]=4;
		return;
	}
	if(a[x+1][y]==tt&&a[x][y-1]==tt)
	{
		a[x][y]=-3;
		a[x+1][y]=-3;
		a[x][y-1]=-3;
		vis[x][y]=3;
		vis[x+1][y]=3;
		vis[x][y-1]=3;
		return;
	}
	if(a[x][y-1]==tt&&a[x-1][y]==tt)
	{
		a[x][y]=-1;
		a[x][y-1]=-1;
		a[x-1][y]=-1;
		vis[x][y]=1;
		vis[x][y-1]=1;
		vis[x-1][y]=1;
		return;
	}
	
}
void dfs(int x,int y,int x0,int y0,int tmp)
{
	if(tmp==1)
		return;
	int t=++cnt;
	tmp/=2;
	if(x0<x+tmp&&y0<y+tmp)
		dfs(x,y,x0,y0,tmp);
	else
    {
        a[x+tmp-1][y+tmp-1]=t;
        dfs(x,y,x+tmp-1,y+tmp-1,tmp);
    }
    if (x0<x+tmp&&y0>=y+tmp)
        dfs(x,y+tmp,x0,y0,tmp);
    else
    {
        a[x+tmp-1][y+tmp]=t;
        dfs(x,y+tmp,x+tmp-1,y+tmp,tmp);
    }
    if (x0>=x+tmp&&y0<y+tmp)
        dfs(x+tmp,y,x0,y0,tmp);
    else
    {
        a[x+tmp][y+tmp-1]=t;
        dfs(x+tmp,y,x+tmp,y+tmp-1,tmp);
    }
    if ( x0>=x+tmp&&y0>=y+tmp)
        dfs(x+tmp,y+tmp,x0,y0,tmp);
    else
    {
        a[x+tmp][y+tmp]=t;
        dfs(x+tmp,y+tmp,x+tmp,y+tmp,tmp);
    }
}
int main()
{
	cin>>n>>x>>y;
	a[x-1][y-1]=-9;
	dfs(0,0,x-1,y-1,n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		change(i,j);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]*-1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
