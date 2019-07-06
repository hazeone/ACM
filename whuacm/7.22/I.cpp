#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
long long n,a[20];
long long ans;
long long getmax(int to)
{
	long long re=0;
	for(int i=1;i<=to/2;i++)re=re*10+7;
	for(int i=1;i<=to/2;i++)re=re*10+4;
	return re;
}
long long getmin(int to)
{
	long long re=0;
	for(int i=1;i<=to/2;i++)re=re*10+4;
	for(int i=1;i<=to/2;i++)re=re*10+7;
	return re;
}
int main()
{
	freopen("I.in","r",stdin);
	//ans=getmax(18);
	//cout<<ans<<endl;
	cin>>T;
	a[1]=1;
	for(int i=2;i<=18;i++)a[i]=a[i-1]*10;
	while(T--)
	{
		cin>>n;
		int tot=0;
		ans=0;
		long long t=n;
		while(t)
		{
			tot++;
			t/=10;
		}
		if(tot==19)
		{
			for(int i=1;i<=10;i++)cout<<4;
			for(int i=1;i<=10;i++)cout<<7;
			cout<<endl;continue;
		}
		if(tot&1)
		{
			cout<<getmin(tot+1)<<endl;continue;
		}
		int len=tot;
		//long long min=getmax(tot);
		//cout<<tot<<" "<<getmin(tot)<<"     ";
		if(n<=getmin(tot))cout<<getmin(tot)<<endl;
		else if(n>getmax(tot)&&tot+2<19)cout<<getmin(tot+2)<<endl;
		else if(n>getmax(tot)&&tot+2>18){
			for(int i=1;i<=10;i++)cout<<4;
			for(int i=1;i<=10;i++)cout<<7;
			cout<<endl;
		}
		else if(n==getmax(tot))cout<<getmax(tot)<<endl;
		else
		{
	        t=getmax(len);
	        ans=t;long long tmp=ans;
	        while(ans>n)
		   {   int v1=0;tot=1;t=ans;tmp=ans;
				 while(tot<=len)
			   {
				  if(!v1&&t%10==7)
				  {
					ans-=a[tot]*3;
					v1=1;
					t/=10;
					tot++;
				  }
				  else if(v1&&t%10==4)
				  {
					ans+=a[tot]*3;
					break;
				   }
				   else
				  {
					t/=10;
					tot++;
				 } 
	           }		
	        }
			cout<<ans<<endl;
		}
	}
}
