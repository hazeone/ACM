/*
 *求（1，1）到（n，m）两条不相交的路径数
*/
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
LL c[2010][2010];
LL mod=1e9+7;
int main()
{
	c[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	while(~scanf("%d%d",&n,&m))
	{
		LL ans=0,x,y;
		x=n-2;
		y=n+m-4;
		if(x<=y)
		{
			ans=c[y][x]*c[y][x]%mod;
		}
		x=m-1;
		LL tmp;
		if(x<=y)
		{
			tmp=c[y][x];
		}
		else tmp=0;
		x=n-1;
		if(x<=y)
		{
			tmp=tmp*c[y][x]%mod;
		}
		else tmp=0;
		ans=(ans-tmp+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
