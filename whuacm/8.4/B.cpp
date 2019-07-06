#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[200000],ans,sum,sum2,b[200000];
int n,k;
int main()
{
	//freopen("B.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	ans+=a[i]*a[i%n+1];
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		long long x=b[i];
		ans=ans+(sum-a[x])*a[x];
		int t=x-1;
		if(t==0)t=n;
		int s=x+1;
		if(s>n)s=1;
		ans=ans-a[x]*a[s]-a[x]*a[t];
		sum2+=a[x];
	}
	long long tmp=0;
	for(int i=1;i<=k;i++)
	{
		tmp+=(a[b[i]]*(sum2-a[b[i]]));
	}
	ans-=(tmp/2);
	sort(b+1,b+1+k);
	for(int i=1;i<k;i++)
	if(b[i]==b[i+1]-1)
	ans+=a[b[i]]*a[b[i+1]];
	if(b[1]==1&&b[k]==n)
	ans+=a[b[1]]*a[b[k]];
	cout<<ans<<endl;
	return 0;
}
