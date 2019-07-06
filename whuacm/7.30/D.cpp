#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long ans;
int n,len;
string s;
int main()
{
	freopen("D.in","r",stdin);
	while(cin>>n)
	{
		getline(cin,s);
		long long cnt1=0,cnt2=0,flag1=0,flag2=0,flag=0,ans=1;
		for(int i=1;i<=n;i++)
		{
			getline(cin,s,'\n');
			if(!flag){
			int len=s.length();
			for(int j=0;j<len;j++)
			{
				if(s[j]=='{')
				{
					flag1=1;
				}
				else if(s[j]=='|'&&flag1)
				{
					cnt1++;
				}
				else if(s[j]=='}')
				{
					ans=ans*(cnt1+1);
					cnt1=flag1=0;
				}
				if(!flag2&&s[j]=='$')
				{
					flag2=1;
				}
				else if(flag2&&s[j]==' ')
				{
					cnt2++;
				}
				else if(flag2&&s[j]!=' '&&s[j]!='$')
				{
					ans=ans*(cnt2+1);
					cnt2=0;
				}
				else if(flag2&&s[j]=='$')
				{
					ans=ans*(cnt2+1);
					cnt2=0;
					flag2=0;
				}
				if(ans>100000)break;
			}
			if(ans>100000)flag=1;}
			
		}
		if(flag)cout<<"doge"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
