#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
LL mod=1e9+7;
LL qpow(LL a,LL b)
{
	LL re=1;
	while(b)
	{
		if(b&1)
		{
			re=re*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return re;
}
LL Euler(LL x)
{
    LL re=x;
    for(LL i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            re=re/i*(i-1);
            while(x%i==0)
            x/=i;
        }
    }
    if(x>1)
    re=re/x*(x-1);
    return re;
}
LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		LL ans=0;
		for(int i=1;i<cas;i++)
		{
			if(gcd(i,cas)==1)
			{
				ans+=i*i;
			}
		}
		LL sq=1LL*cas*(cas+1)*(2*cas+1)/6LL;
		cout<<cas<<" "<<ans<<" "<<sq<<" "<<sq-ans<<" "<<Euler(cas)<<endl;
	}
	return 0;
}
