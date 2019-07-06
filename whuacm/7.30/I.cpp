#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long h,a,b,k;
int main()
{
	for(int T=1;;T++)
	{
		cin>>h>>a>>b>>k;
		if(!h&&!a&&!b&&!k)break;
		if(h<=a)
		{
			cout<<"Case #"<<T<<": "<<"YES"<<endl;
		}
		else if(b-a>=0)
		{
			cout<<"Case #"<<T<<": "<<"NO"<<endl;
		}
		else if((a-b)*(k-1)+a>=h)
		{
			cout<<"Case #"<<T<<": "<<"YES"<<endl;
		}
		else if(b*(k+1)-a*k>=0)
		{
			cout<<"Case #"<<T<<": "<<"NO"<<endl;
		}
		else cout<<"Case #"<<T<<": "<<"YES"<<endl;
		
	}
	return 0;
}


