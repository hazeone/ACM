#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,c,x,k;
long long t;
long long ksm(long long a,long long b)
{
	long long re=a,ans=0;
	while(b)
	{
		if(b&1)
		{
			ans=(ans+re)%t;
		}
		re=(re*re)%t;
		b/=2;
	}
	return ans;
}
int main()
{
	t=1<<16;
	t=t*t;
	cout<<t;
	cout<<ksm(233,19)<<endl;
	return 0;
}
