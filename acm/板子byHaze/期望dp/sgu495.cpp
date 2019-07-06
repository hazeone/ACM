#include<bits/stdc++.h>
using namespace std;
int n,m;
double dp[100010];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		 dp[m]=0;
		 for(int i=m-1;i>=0;i--)
		 {
			 dp[i]=(double)(n-1)/(double)n*dp[i+1]+1.0;
		 }
		 printf("%.9lf\n",dp[0]);
	}
	return 0;
}
