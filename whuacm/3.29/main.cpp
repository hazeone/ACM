#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,len,t[100010][2];
LL a,b,c,d,start;
LL dp[150010][18],dp2[150010][18];
LL sum[150000],sum2[150000];
void clr()
{
	sum2[0]=0;
	sum[0]=start;
}
void rmp_st()
{
    for(int i=1;i<=n;i++)
        dp[i][0]=sum[i];
    int m=(int)(log((double)n)/log(2.0)));
	for(int j=1;j<=m;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<j)][j-1]);
    }
}
void rmp_st2()
{
    for(int i=1;i<=n;i++)
        dp2[i][0]=sum2[i];
    int m=(int)(log((double)n)/log(2.0)));
	for(int j=1;j<=m;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<j)][j-1]);

    }
}
LL rmp_find(int l,int r)
{
    int k=(int)(log(double(r-l+1))/log(2.0));
    return min(dp[l][k],dp[r-(1<<k)+1][k])

}
LL rmp_find2(int l,int r)
{
    int k=(int)(log(double(r-l+1))/log(2.0));
    return min(dp2[l][k],dp2[r-(1<<k)+1][k])

}
int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%lld %lld %lld %lld %lld %d",&a,&b,&c,&d,&start,&len);
		clr();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&t[i][0],&t[i][1]);
			if(t[i][1])
			{
				sum[i]=sum[i-1]+a;
				sum2[i]=sum2[i-1]+c;
			}
			else
			{
				sum[i]=sum[i-1]-b;
				sum2[i]=sum2[i-1]-d;
			}
		}
		rmp_st();rmp_st2();
		int x=0,cnt0=0,cnt1=0;
		LL ans=0;
		while(t[x+1][0]<len&&x<n)
		{
			x++;
			if(t[x][1])cnt1++;
			else cnt0++;
		}

	}
	return 0;
}
