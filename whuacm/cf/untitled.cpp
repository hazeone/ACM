#include<bits/stdc++.h>
using namespace std;
#define LL long long;
int n,m;
int a[100010],b[100010];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	sort(a+1,a+1+n);
	a[0]=-1;
	m=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		b[++m]=1;
		else b[m]++;
	}
	int ans=0,now=b[1];
	for(int i=2;i<=m;i++)
	{
		if(now<=b[i])
		{
			ans+=now;
			now=b[i];
		}
		else
		{
			ans+=b[i];
			now=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}
