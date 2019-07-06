#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

long long a[300100],f[300100];
const long long MOD=1000000007;
int n;


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	f[i]=(f[i-1]*2)%MOD;
	long long ans=0,tmp;
	for(int i=1;i<n;i++)
	{
		//if(pow(2,i)-1<0||pow(2,n-i)-1<0)while(1);
		tmp=(f[i]-1)*(f[n-i]-1);
		tmp%=MOD;
		tmp=tmp*((a[i+1]-a[i])%MOD);
		tmp%=MOD;
		ans+=tmp;
		ans%=MOD;
		if(ans<0)
		{
			cout<<ans<<" "<<i<<endl;
			return 0;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
