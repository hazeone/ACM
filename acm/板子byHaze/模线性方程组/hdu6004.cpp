#include<bits/stdc++.h>

using namespace std;
#define LL long long
#define LLL __int128
const int N=202;
const int M=N*N/2+N;

struct num
{
	LL r,a;
}dp[N][M];
int T,n,m,Q;
inline int cal(int x,int y)
{
	return (2*m-x+2)*(x-1)/2+y-x+1;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	LL tmp=exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return tmp;
}
num merge(num x,num y)
{
	if(x.r==-1||y.r==-1)return {-1,-1};
	LL x0,y0,d;
	d=exgcd(x.a,y.a,x0,y0);
	if((x.r-y.r)%d)return {-1,-1};
	LLL t=(x.r-y.r)/d;
	LLL R=(LLL)x.r-(LLL)x.a*x0*t;
	LLL A=(LLL)x.a/d*(LLL)y.a;
	R=(R%A+A)%A;
	return {(LL)R,(LL)A};
}
void pre()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=j+1;k<=m;k++)
				dp[i][cal(j,k)]=merge(dp[i][cal(j,k-1)],dp[i][cal(k,k)]);
}
int main()
{
	while(~scanf("%d",&T))
	{
		for(int p=1;p<=T;p++)
		{
			printf("Case #%d:\n",p);
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					scanf("%lld",&dp[i][cal(j,j)].r);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					scanf("%lld",&dp[i][cal(j,j)].a);
			pre();
			scanf("%d",&Q);
			while(Q--)
			{
				int x,y,xx,yy;
				scanf("%d%d%d%d",&x,&y,&xx,&yy);
				num ans=dp[x][cal(y,yy)];
				for(int i=x+1;i<=xx;i++)
				{
					if(ans.r==-1)break;
					ans=merge(dp[i][cal(y,yy)],ans);
				}
				printf("%lld\n",ans.r);
			}
		}
	}
	return 0;
}
