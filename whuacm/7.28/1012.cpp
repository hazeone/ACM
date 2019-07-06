#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int a[200000],t[200000],n,ans[200000];
int lowbit(int x)
{
	return x&-x;
}
int getsum(int x)
{
	int re=0;
	for(;x;x-=lowbit(x))
	re+=t[x];
	return re;
}
void add(int x)
{
	for(;x<=n;x+=lowbit(x))
	t[x]++;
}
int main()
{
	freopen("1012.in","r",stdin);
	int T;cin>>T;
	for(int p=1;p<=T;p++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			t[i]=0;
			ans[i]=0;
		}
		for(int i=n;i>=1;i--)
		{
			ans[a[i]]=i+getsum(a[i])-min(a[i],i);
			add(a[i]);
		}
		cout<<"Case #"<<p<<":";
		for(int i=1;i<=n;i++)
		cout<<" "<<ans[i];
		cout<<endl;
	}
	return 0;
}
