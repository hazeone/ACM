#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define LL long long
int n,k,m,sb[2010][2010],sw[2010][2010],p,q;
void clear()
{
	memset(sb,0,sizeof(sb));
	memset(sw,0,sizeof(sw));
}
void cal()
{
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
		sb[i][j]+=sb[i][j-1]+sb[i-1][j]-sb[i-1][j-1];
		sw[i][j]+=sw[i][j-1]+sw[i-1][j]-sw[i-1][j-1];
	}
}
int calb(int mx,int my,int nx,int ny)
{
	mx+=p;nx+=p;
	my+=q;ny+=q;
	if(mx>m||my>m||nx<1||ny<1)return 0;
	mx=max(1,mx);my=max(1,my);
	nx=min(m,nx);ny=min(m,ny);
	return sb[nx][ny]-sb[nx][my-1]-sb[mx-1][ny]+sb[mx-1][my-1];
}
int calw(int mx,int my,int nx,int ny)
{
	mx+=p;nx+=p;
	my+=q;ny+=q;
	if(mx>m||my>m||nx<1||ny<1)return 0;
	mx=max(1,mx);my=max(1,my);
	nx=min(m,nx);ny=min(m,ny);
	return sw[nx][ny]-sw[nx][my-1]-sw[mx-1][ny]+sw[mx-1][my-1];
}
int main()
{
	while(cin>>n>>k)
	{
		clear();
		int x,y;
		char s[3];
		m=k*2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%s",&x,&y,s);
			if(s[0]=='W')
			{
				sw[x%m+1][y%m+1]++;
			}
			else sb[x%m+1][y%m+1]++;
		}
		cal();
		int ans=-1,t;
		for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
		{
			p=i,q=j;
			t=calb(1,1,k,k)+calb(k+1,k+1,k+k,k+k)+calb(-k+1,-k+1,0,0)+calb(-k+1,k+1,0,k+k)+calb(k+1,-k+1,2*k,0)+calw(k+1,1,2*k,k)+calw(1,k+1,k,2*k)+calw(1,-k+1,k,0)+calw(-k+1,1,0,k);
			ans=max(t,ans);
			t=calw(1,1,k,k)+calw(k+1,k+1,k+k,k+k)+calw(-k+1,-k+1,0,0)+calw(-k+1,k+1,0,k+k)+calw(k+1,-k+1,2*k,0)+calb(k+1,1,2*k,k)+calb(1,k+1,k,2*k)+calb(1,-k+1,k,0)+calb(-k+1,1,0,k);
			ans=max(t,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
