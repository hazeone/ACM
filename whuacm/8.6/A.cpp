#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,pos=1;
char s[1000];
long long ans;
int main()
{
	freopen("A.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='A'||s[0]=='O'||s[0]=='R'||s[0]=='P')
		{
			ans=ans+pos-1;
			pos=1;
		}
		if(s[0]=='B'||s[0]=='M'||s[0]=='S')
		{
			ans=ans+abs(pos-2);
			pos=2;
		}
		if(s[0]=='D'||s[0]=='J'||s[0]=='G'||s[0]=='K'||s[0]=='T'||s[0]=='W')
		{
			ans=ans+3-pos;
			pos=3;
		}
	}
	cout<<ans<<endl;
	return 0;
}
