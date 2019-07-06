#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int T,n,a[200000],sum,mod=100000007;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
void dfs(int pos,int gc)
{
	//cout<<pos<<" "<<gc<<" "<<sum<<endl;
	if(pos==n+1)return;
	dfs(pos+1,gc);
	if(gc==0)
	{
		gc=a[pos];
		sum=(sum+gc)%mod;
		//cout<<"     1      "<<gc<<endl;
		dfs(pos+1,gc);
	}
	else
	{//cout<<gc;
		//cout<<a[pos]<<" "<<gc<<" ";
		gc=gcd(a[pos],gc);//cout<<gc<<endl;
		sum=(sum+gc)%mod;
		//cout<<"    2      "<<gc<<endl;
		dfs(pos+1,gc);
	}
}
int main()
{//cout<<gcd(3,2);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sum=0;
		dfs(1,0);
		cout<<sum<<endl;
	}
	return 0;
}
