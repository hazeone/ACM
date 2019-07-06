#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	long long l,r,ans,t;
	while(cin>>l>>r)
	{
		t=-1;
		for(long long i=l;i<=r;i++)
		{
			long long x=i,y=-1;
			while(x)
			{
				if(x%10>y)
				{
					y=x%10;
				}
				x/=10;
			}
			if(y>t)
			{
				ans=i;
				t=y;
			}
			if(t==9)
			break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
