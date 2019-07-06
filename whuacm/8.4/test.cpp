#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n;
long long a[200000],f[70],b[200000];
long long ab(long long x)
{
	return x<0?-x:x;
}
int main()
{
	f[0]=1;
	for(int i=1;i<62;i++)
	f[i]=f[i-1]<<1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long ans=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<n;i++)
		sum+=ab(a[i]-a[i+1]);
		for(int k=0;k<21;k++)
		{
			for(int i=1;i<=n;i++)
			b[i]=a[i];
			for(int i=1;i<=n;i++)
			b[i]^=f[k];
			long long tmp=0;
			for(int i=1;i<n;i++)
			tmp+=ab(b[i]-b[i+1]);
			if(tmp<sum)ans+=f[k];
		}
		sum=0;
		for(int i=1;i<=n;i++)
		a[i]^=ans;
		for(int i=1;i<n;i++)
		sum+=ab(a[i]-a[i+1]);
		cout<<ans<<" "<<sum<<endl;
	}
	return 0;
}
