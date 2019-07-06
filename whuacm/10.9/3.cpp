#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e6+10;
LL g[N],f[N],sum[N];
LL mod=100000073;
inline int tran(int x)
{
	if(x<0)return N-1;
	else return x;
}
int main()
{
	f[0]=1;sum[0]=1;
	g[1]=f[1]=1;
	sum[1]=2;
	int now=1,c=1;
	for(int i=2;i<N-2;i++)
	{
		if(c==now)
		{
			now++;
			c=1;
		}
		g[i]=now;
		if(c==1)
		f[i]=(sum[i-1]-sum[tran(i-now-2)]+mod)%mod;
		else
		f[i]=(f[i-1]-f[i-c]+mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		c++;
	}
	LL x,y;
	while(~scanf("%lld%lld",&x,&y))
	{
		printf("%lld %lld\n",g[y-x+1],f[y-x+1]);
	}
	return 0;
}
