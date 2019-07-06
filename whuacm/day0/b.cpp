#include<bits/stdc++.h>
using namespace std;

#define LL long long

LL n,m;
LL g[100010],f[100100];

int main()
{
	f[0]=1;
	f[2]=1;
	f[3]=1;
	g[3]=1;
	while(~scanf("%lld%lld",&n,&m))
	{

		for(LL i=4;i<=n;i++)
		{
			f[i]=f[i-2]*(i-1)%m;
			g[i]=(g[i-1]*(i-1)%m+((i-1)*(i-2)/2)%m*f[i-3]%m)%m;
			f[i]=(f[i]+g[i])%m;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}
