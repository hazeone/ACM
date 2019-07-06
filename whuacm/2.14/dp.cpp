#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[400002],now,rig[400001],n,a[400001],c[400001],mx;
void solve(int x)
{
	while(mx<=x)
	{
		now--;
		int p=rig[now];
		c[p]=1;
		while(p>0)
		{
			dp[p]=c[p]+max(dp[p*2+1],0)+max(dp[p*2],0);
			mx=mx>dp[p]?mx:dp[p];
			p=p/2;
		}
		
	}
	printf("%d ",now);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			rig[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
		dp[i]=-1,c[i]=-1;
		now=n+1;mx=-1;
		for(int i=0;i<n;i++)
		solve(i);
		printf("\n");
	}return 0;
}
