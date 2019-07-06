#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	double c;
	int k,t;
}a[200000];
int n;
bool cmp(point x,point y)
{
	return x.c<y.c;
}
int main()
{
	while(cin>>n)
	{
		long long sum=0,ans=0;
		for(int i=1;i<=n;i++)
	scanf("%d",&a[i].t);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].k);
	for(int i=1;i<=n;i++)
	a[i].c=(a[i].t*1.0)/(a[i].k*1.0);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i].t;
		ans+=sum*a[i].k;
	}
	cout<<ans<<endl;
	}
	return 0;
}
