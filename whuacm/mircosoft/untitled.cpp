#include <bits/stdc++.h>
using namespace std;
#define ll long long
int sum[1005],co[1005],lc[1005],rc[1005];
ll f[1005];
int n,k;
ll M = 1e9;
struct point
{
	int c;
	ll p;
}a[1005];
bool cmp(point A,point B)
{
	if(A.c==B.c)
	return A.p<B.p;
	return A.c<B.c;
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i].p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].c);
	sort(a+1,a+1+n,cmp);
	memset(co,0,sizeof(co));
	memset(rc,0,sizeof(rc));
	memset(lc,0,sizeof(lc));
	memset(sum,0,sizeof(sum));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		if(lc[a[i].c]==0)
		{
			lc[a[i].c]=i;
		}
		rc[a[i].c]=i;
		sum[i]=++co[a[i].c];
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i].c<<" "<<a[i].p<<" "<<sum[i]<<endl;
	}*/
}
int main() {
    int T;
    M=M*M;
    scanf("%d", &T);
    for(int ca=1;ca<=T;ca++)
    {
		init();
		ll ans=M;
		//cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			if(sum[i]>k)continue;
			int m=k-sum[i];
			f[0]=a[i].p;
			for(int j=1;j<=m;j++)
			{
				f[j]=M;
			}
			for(int j=1;j<=1000;j++)
			{
				if(lc[j]==0||j==a[i].c)continue;
				for(int q=rc[j];q>=lc[j];q--)
				{
					for(int p=m;p>=sum[q];p--)
					{
						f[p]=min(f[p],f[p-sum[q]]+a[q].p*2);
					}
				}
			}
			ans=min(ans,f[m]);
		}
		printf("Case #%d: ",ca);
		cout<<ans<<endl;
    }
    return 0;
}
