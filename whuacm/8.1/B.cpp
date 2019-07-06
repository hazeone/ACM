#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
long long f[70],n,k;
int T;
int main()
{
	freopen("B.in","r",stdin);
	cin>>T;
	f[0]=1;
	for(int i=1;i<62;i++)f[i]=f[i-1]<<1;
	for(int p=1;p<=T;p++)
	{
		cin>>n>>k;
		long long sum=f[k]-1-n;
		int flag=0;
		if(sum%2)
		{
			flag=1;
			sum++;
		}
		sum=sum>>1;
		cout<<"Case #"<<p<<": "<<endl;
		for(int i=0;i<k-1;i++)
		{
			if(f[i]&sum)
			{
				cout<<f[i]<<" -"<<endl;
			}
			else
			{
				cout<<f[i]<<" +"<<endl;
			}
		}
		if(flag)
		cout<<f[k-1]+1<<" +"<<endl;
		else
		cout<<f[k-1]<<" +"<<endl;
	}
	return 0;
}
