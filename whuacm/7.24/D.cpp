#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int p,k;
int main()
{
	while(cin>>k>>p)
	{
		int t=k/(p-1);
		if(t&1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
