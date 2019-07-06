#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=30;
LL mod=1000000007;
int n,t,a[N],p[N];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[p[i]=i];
	sort(p+1,p+n+1,cmp);
	for(int i=2;i<=n;i++)
	swap(a[p[i]],a[p[i-1]]);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<' ';
	return 0;
}
