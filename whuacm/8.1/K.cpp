#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
string s;
int T,tot;
long long a[200001];
int main()
{
	freopen("K.in","r",stdin);
	cin>>T;
	getline(cin,s);
	for(int p=1;p<=T;p++)
	{
		memset(a,0,sizeof(a));
		getline(cin,s,'\n');
		int len=s.length();
		if(len==0)
		{
			cout<<"Case #"<<p<<": "<<0<<endl;
			continue;
		}
		tot=0;
		long long ll=1,ans=0,up=0;
		char nod=s[0];
		for(int i=1;i<len;i++)
		{
			if(s[i]==nod)
			{
				ll++;
			}
			else
			{
				a[++tot]=ll;
				ll=1;
				nod=s[i];
			}
		}
		a[++tot]=ll;
		if(tot>1)
		for(int i=1;i<=tot;i++)
		{
			ans+=a[i]*a[i];
			if(i<tot)
			{
				up=max(up,2*(max(a[i],a[i+1])-min(a[i],a[i+1]))+2);
			}
			if(a[i]==1&&i>1&&i<tot)
			{
				up=max(up,2*(a[i-1]*a[i+1]+a[i-1]+a[i+1]));
			}
		}
		else
		{
			ans=a[1]*a[1];up=0;
		}
		cout<<"Case #"<<p<<": "<<ans+up<<endl;
	}
	return 0;
}
