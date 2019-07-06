#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n;
int l[205],r[205];
int mnh,mxh;
LL f[10001][101];
LL inv2=500000004,mod=1e9+7;
LL sum[10001];
LL qpow(LL a,LL b)
{
	LL re=1;
	while(b)
	{
		if(b&1)re=re*a%mod;
		a=a*a%mod;
		b=b>>1;
	}
	return re;
}
int main()
{
	//cout<<inv2*2%mod<<endl;
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			scanf("%d",&n);
			mnh=0,mxh=0;
			for(int i=1;i<=n;i++)
			{
				scanf("%d%d",&l[i],&r[i]);
				mnh=max(l[i],mnh);
				mxh=max(r[i],mxh);
			}
			for(int j=0;j<=n;j++)
			for(int i=0;i<=mxh;i++)
			f[i][j]=0;
			for(int i=1;i<=n;i++)
			{
				for(int k=mnh;k<=mxh;k++)
				{
					LL tmp=min(k,r[i])-l[i]+1;
					//cout<<i<<" "<<k<<" "<<tmp<<" "<<k-l[i]+1+k-min(k,r[i])+1<<" ";
					tmp=tmp%mod*(LL)(k-l[i]+1+k-min(k,r[i])+1)%mod*inv2%mod;
					//cout<<tmp<<endl;
					f[k][i]=tmp%mod;
				}
				for(int k=mxh;k>=mnh;k--)
				{
					f[i][k]-=f[i][k-1];
				}
			}

			LL ans=0;
			for(int i=mnh;i<=mxh;i++)
			{
				for(int j=2;j<=n;j++)
				f[i][1]=f[i][j]%mod*f[i][1]%mod;
				ans=(ans+f[i][1])%mod;
			}
			LL inv=1;
			for(int i=1;i<=n;i++)
			{
				inv=inv*qpow(r[i]-l[i]+1,mod-2)%mod;
			}
			//cout<<inv<<endl;
			cout<<ans*inv%mod<<endl;
		}
	}
	return 0;
}
