#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
char a[2000];
int main()
{
	while(cin>>a)
	{
		if(strlen(a)>10)
		{
			cout<<"TAT"<<endl;
			continue;
		}
		long long n=0;
		for(int i=0;i<strlen(a);i++)
		n=n*10+a[i]-'0';
		if(n<1||n>4294967295)
		{
			cout<<"TAT"<<endl;
		}
		else if(n<=4294967295&&n>65535)
		{
			cout<<5<<endl;
		}
		else if(n<=65535&&n>255)
		{
			cout<<4<<endl;
		}
		else if(n<=255&&n>15)
		{
			cout<<3<<endl;
	    }
	    else if(n<=15&&n>3)
	    {
			cout<<2<<endl;
		}
		else if(n<=3&&n>1)
		{
			cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
