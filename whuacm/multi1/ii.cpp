#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=1e9+7;
const int N=105;
const int M=2005;
int n,m;
LL a[N],v[N],g[N][N];
LL id[N][N][N],dp[M][N],w[M][N],f[N][M];
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
//LL po(LL a,LL b){LL t=1;for(;b;b>>=1,a=1LL*a*a%mod)if(b&1)t=1LL*t*a%mod;return t;}
LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}
inline void up(LL&a,LL b)
{
	a=a+b<mod?a+b:a+b-mod;
}
int main()
{
	int T;
	while(~scanf("%d",&T))
	{
		while(T--)
		{
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
			for(int i=1;i<=m;i++)
			scanf("%lld",v+i);
			for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
			g[i][j]=gcd(i,j);
			int cnt=0;
			for(int i=1;i<=m;i++)
				for(int j=i;j<=m;j+=i)
					for(int k=j;k<=m;k+=j)
					id[i][j][k]=++cnt;
			for(int i=1;i<=m;i++)
				for(int j=i;j<=m;j+=i)
					for(int k=j;k<=m;k+=j)
					{
						int x=id[i][j][k];
						for(int y=1;y<=m;y++)
						{
							dp[x][y]=id[g[j][y]][g[k][y]][y];
							w[x][y]=v[g[i][y]];
						}
					}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=cnt;j++)
				f[i][j]=0;
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					for(int k=1;k<=m;k++)
					{
						  if(a[1]&&i!=a[1])continue;
						  if(a[2]&&j!=a[2])continue;
						  if(a[3]&&k!=a[3])continue;
						  up(f[3][id[g[g[i][j]][k]][g[j][k]][k]],1);
					}
			for(int i=3;i<n;i++)
				for(int j=1;j<=cnt;j++)
					if(f[i][j])
					{
						for(int k=1;k<=m;k++)
						{
							if(a[i+1]&&k!=a[i+1])continue;
							up(f[i+1][dp[j][k]],f[i][j]*w[j][k]%mod);
						}

					}
			LL ans=0;
			for(int j=1;j<=cnt;j++)
			up(ans,f[n][j]);
			//cout<<m<<" "<<ans<<endl;
			for(int i=1;i<=n;i++)
			if(!a[i])
			ans=ans*qpow(m,mod-2)%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
