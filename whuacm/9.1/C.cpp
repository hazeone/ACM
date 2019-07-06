#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
long long ans,a[10],b[10];
int n;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	//freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>b[i];
	sort(b+1,b+1+n,cmp);
	ans=b[1];a[1]=b[1];
	int flag=0;
	for(int i=2;i<=n;i++)
	{//cout<<ans<<endl;
		long long tmp=0;
		for(int j=1;j<i;j++)
		{
			if(a[j])
			{
				a[j]--;
				tmp++;
			}
			if(tmp==b[i])break;
		}
		a[i]=b[i]-tmp;
		if(i<=4)
		ans+=a[i];
		if(i==4&&tmp==0)
		{
			flag=3;
			a[i]--;
			ans--;
		}
		if(i==4&&tmp==1)
		{
			flag=2;
			a[i]--;
			ans--;
		}
		if(i==4&&tmp==2)flag=4;
		if(i==4&&tmp==3)flag=1;
		if(i==5)
		{//cout<<flag<<" "<<tmp<<endl;
			//cout<<ans<<endl;
			if(flag==3)
			ans+=a[i]-1;
			if(flag==2)
			{
				ans+=b[i]-1-tmp;
			}
			if(flag==1||flag==4)
			{
				tmp++;
				tmp=max(tmp,(long long)2);
				ans+=max(b[i]-tmp,(long long)0);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
