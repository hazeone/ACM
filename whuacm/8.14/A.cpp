#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int T,n,len;
string s;
long long a[200000];
int main()
{
	freopen("1.cpp","r",stdin);
	cin>>T;
	for(int p=1;p<=T;p++)
	{
		cin>>s;
		int n=s.length();
		len=0;
		for(int i=0;i<26;i++)
		a[i]=0;
		for(int i=0;i<n;i++)
		a[s[i]-'a']++;
		for(int i=0;i<26;i++)
		if(a[i])len++;
		cout<<"Case #"<<p<<": "<<len<<endl;
	}
	return 0;
}
