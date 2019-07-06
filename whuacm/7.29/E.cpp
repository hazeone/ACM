#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long f1[1001][1026],f2[1001][1026],mod=1000000007;
int a[1001],T,n;
int main()
{
	freopen("E.in","r",stdin);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			f1[i][a[i]]=1;
			for(int j=0;j<1024;j++)
			if(f1[i-1][j])
			{
				f1[i][j]=(f1[i-1][j]+f1[i][j])%mod;
				f1[i][j^a[i]]=(f1[i][j^a[i]]+f1[i-1][j])%mod;
			}
		}
		for(int i=n;i>1;i--)
		{
			f2[i][a[i]]=1;
			for(int j=0;j<1024;j++)
			if(f2[i+1][j])
			{
				f2[i][j]=(f2[i][j]+f2[i+1][j])%mod;
				f2[i][j&a[i]]=(f2[i][j&a[i]]+f2[i+1][j])%mod;
			}
		}
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<1024;j++)
			{
				if(f1[i][j]&&f2[i+1][j])
				ans=((ans+(((f1[i][j]-f1[i-1][j])%mod)*f2[i+1][j]))%mod)%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
