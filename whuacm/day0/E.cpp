#include<bits/stdc++.h>
using namespace std;
const int N=100100;
#define LL long long
int n,m,k;
int nxt[N][11],p[11];
LL f[N][11];
LL mod=1e9+7;
int s[N];
int main()
{
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
		for(int i=1;i<=k;i++)
		p[i]=nxt[n+1][i]=n+1;
		for(int i=n;i>=0;i--)
		{
			for(int j=1;j<=k;j++)
			{
				nxt[i][j]=p[j];
			}
			p[s[i]]=i;
		}
		for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
		f[i][j]=0;
		f[0][0]=1;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=i&&j<=m;j++)
			{
				for(int c=1;c<=k;c++)
				{
					if(nxt[i][c]<=n&&j+nxt[i][c]-i-1<=min(nxt[i][c],m))
					{
						f[nxt[i][c]][j+nxt[i][c]-i-1]=(f[nxt[i][c]][j+nxt[i][c]-i-1]+f[i][j])%mod;
					}
				}
			}
		}
		LL ans=0;
        for(int i=0;i<=m;i++)
        {
            ans=ans+f[n-i][m-i];
            ans%=mod;
        }
        cout<<ans<<endl;
	}
	return 0;
}
