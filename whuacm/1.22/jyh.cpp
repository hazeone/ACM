#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
#define ll long long
int n,m,T,k;
ll a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	cout<<n+n%2<<endl;
	int max=1e6;
	for(int i=0;i<n;i++)
	{
		if(i%2)
		{
			printf("2 %d ",n-i);
			cout<<max<<endl;

		}
		else{
			printf("1 %d ",n);
			cout<<max<<endl;
		}
	}
	if(n%2)cout<<"2 1 1"<<endl;
	return 0;
}
