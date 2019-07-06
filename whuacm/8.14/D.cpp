#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,T;
int a[1000],s,sum;
int main()
{
	freopen("1.cpp","r",stdin);
	cin>>T;
	for(int p=1;p<=T;p++)
	{
		s=sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		int tmp=s/2,targ;
		//if(tmp&1)tmp++;
		targ=tmp/2;
		sort(a+1,a+1+n);
		sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=a[i];
			if(sum>targ)break;
		}
		//cout<<s<<" "<<tmp<<" "<<targ<<endl;
		cout<<"Case #"<<p<<": ";
		if(sum==0)
		{
			if(s>1)
			cout<<1<<endl;
			else
			cout<<0<<endl;
		}
		else
		cout<<min(sum*2+1,s>>1)<<endl;
		
	}
	return 0;
}
