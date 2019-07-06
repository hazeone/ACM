#include<bits/stdc++.h>
using namespace std;
const int N=1010010;
double dp[N];
double eps=0.0000001;
int n,f;
int c[101];
int t[101];
double dfs(int now)
{
	if(abs(dp[now])>eps)
	{
		return dp[now];
	}
	for(int i=1;i<=n;i++)
	{
		if(now>c[i])
		{
			dp[now]+=(double)t[i];
		}
		else dp[now]+=(dfs(now+c[i])+1.0);
	}
	dp[now]=dp[now]/(double)n;
	return dp[now];
}
int main()
{
	while(~scanf("%d%d",&n,&f))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",c+i);
			double tmp=(1.0+sqrt(5.0))/2.0*(double)c[i]*c[i];
			t[i]=tmp;
		}
		for(int i=f;i<N;i++)
		dp[i]=0.0;
		printf("%.3lf\n",dfs(f));
	}
   return 0;
}
