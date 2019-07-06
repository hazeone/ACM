#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,a[200000],sum[200000],s[200000],m;
int main()
{
	freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	sort(a+1,a+1+n);
	s[0]=sum[0];
	for(int i=1;i<=100000;i++)
	s[i]=sum[i]+s[i-1];
	cin>>m;
	while(m--)
	{
		int x;
		scanf("%d",&x);
		if(x>=100000)
		cout<<n<<endl;
		else cout<<s[x]<<endl;
	}
	return 0;
}
