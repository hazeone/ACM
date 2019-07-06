#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int T,n;
long long f[1005][1005],g[1005][1005],a[1000000],mod=100000007	;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	freopen("HDU5656.in","r",stdin);
	cin>>T;
	for(int i=1;i<=1000;i++)
	for(int j=i;j<=1000;j++)
	g[i][j]=g[j][i]=gcd(i,j);
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=1001;i++)
		for(int j=1;j<=1001;j++)
		f[i][j]=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			f[i][a[i]]++;
			for(int j=1;j<=1000;j++)
			{
				f[i+1][j]+=f[i][j];
				f[i+1][g[a[i+1]][j]]+=f[i][j];
				f[i+1][j]%=mod;
				f[i+1][g[a[i+1]][j]]%=mod;
			}
		}
		for(long long i=1;i<=1000;i++)
		ans=(ans+f[n+1][i]*i)%mod;
		cout<<ans<<endl;
		cout<<"asfagasd"<<endl;
	}
	return 0;
}
