#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,seed;
int main()
{while(cin>>n>>seed)
{	long long x=seed;
	for(int i=2;i<=n;i++)
	{
		x=(x*907)%2333333;
		long long T=x;
		int ma=max(1,i-5);
		for(int j=ma;j<n;j++)
		{
			x=(x*907)%2333333;
			cout<<j<<" "<<i<<" "<<(T^x)<<endl;
		}
	}
}
	return 0;
}
