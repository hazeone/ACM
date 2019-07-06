#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int T,a[200000],n;
int main()
{
	cin>>T;
	while(T--)
	{
		int v1=0,v2=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==0)v1=1;
			if(a[i]==1)v2=1;
		}
		if(v1&&v2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
