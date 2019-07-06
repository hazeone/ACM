#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int T,ans,n;
int main()
{
	freopen("G.in","r",stdin);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=-1000000001;
		while(n--)
		{
			int x;
			cin>>x;
			if(x>ans)ans=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}

