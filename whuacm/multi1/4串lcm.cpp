#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1005;
LL mod=1000000007;
LL pw[N],inv[N];
int n,m;
LL p[N];
LL qpow(LL a,LL b)
{
	LL re=1;
	while(b)
	{
		if(b&1)re=re*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return re;
}
int main()
{
	scanf("%d%d",&n,&m);
	pw[0]=0;
	inv[0]=1;
	for(int i=1;i<N;i++)
	{inv[i]=qpow(qpow(100,i),mod-2);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		pw[i]=qpow(i,m);
	}
	LL ans=0;
	p[0]=0;
	p[n+1]=0;
	//cout<<10000LL*inv[1]%mod<<endl;
	for(int i=1;i<=n;i++)
	{
		LL tmp=100-p[i-1];
		for(int j=i;j<=n;j++)
		{
			tmp=(tmp*p[j])%mod;
			ans=(ans+pw[j-i+1]*tmp%mod*(100LL-p[j+1])%mod*inv[j-i+3]%mod)%mod;
			//cout<<tmp<<" "<<pw[j-i+1]<<" "<<(100LL-p[j+1])<<" "<<inv[j-i+3]%mod<<" ";
			//cout<<ans<<" "<<pw[j-i+1]*tmp%mod*(100LL-p[j+1])%mod*inv[j-i+3]%mod<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
