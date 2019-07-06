#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
long long n,a[100000];
int main()
{
	freopen("J.in","r",stdin);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		if(n<=2)
		{
			cout<<1<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<2<<endl;
			continue;
		}
		a[1]=1;
		a[2]=2;
		int tot=2;
		n-=3;
		while(n>=a[tot]+a[tot-1])
		{
			n=n-a[tot]-a[tot-1];
			tot++;
			a[tot]=a[tot-1]+a[tot-2];
		}
		cout<<tot<<endl;;
	}
	return 0;
}
