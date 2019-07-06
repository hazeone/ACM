#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n,tot;
long long ans,num[200000],a[200000],f[200000][2];
int main()
{
	freopen("G.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	if(n==1)
	{
		cout<<num[1]<<endl;return 0;
	}
	int l=1,r=0,begin=1;
	for(int i=2;i<=n;i++)
	{
		if(num[i]==num[i-1]+1)
		{
			long long tmp=i-begin;
			a[++tot]=tmp*num[i-1];r=tot;
			begin=i;
		}
		else if(num[i]>num[i-1]+1)
		{
			long long tmp=i-begin;
			a[++tot]=tmp*num[i-1];r=tot;
			f[l][1]=a[l];
			for(int j=l+1;j<=r;j++)
			{
				f[j][0]=max(f[j-1][0],f[j-1][1]);
				f[j][1]=max(f[j-1][0]+a[j],f[j-1][1]);
		    }
		    ans+=max(f[r][0],f[r][1]);
		    //cout<<ans<<endl;
		    begin=i;
		    l=tot+1;
		}
		if(i==n)
		{
			long long tmp=i-begin+1;
			a[++tot]=tmp*num[i];r=tot;
			f[l][1]=a[l];
			for(int j=l+1;j<=r;j++)
			{
				f[j][0]=max(f[j-1][0],f[j-1][1]);
				f[j][1]=max(f[j-1][0]+a[j],f[j-1][1]);
		    }
		    ans+=max(f[r][0],f[r][1]);
		    //cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
