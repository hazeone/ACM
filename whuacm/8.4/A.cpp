#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int s1=0,s2=0;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)s1++;
		if(y>x)s2++;
	}
	if(s1>s2)cout<<"Mishka"<<endl;
	if(s2>s1)cout<<"Chris"<<endl;
	if(s2==s1)cout<<"Friendship is magic!^^"<<endl;
	return 0;
	
}
