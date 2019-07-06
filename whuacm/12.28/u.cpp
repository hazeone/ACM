#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,int> mymap;
LL id[800010];
LL cnt;
LL a[800010];
LL num[800010];
int n;
LL l[800010],r[800010],tmp[800010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		tmp[i]=l[i];
		tmp[n+i]=r[i];
		tmp[n*2+i]=l[i]+1;
		tmp[n*3+i]=r[i]+1;
	}
	sort(tmp+1,tmp+1+4*n);
	int now=0;
	tmp[0]=-1;
	for(int i=1;i<=4*n;i++)
	{
		if(tmp[i]!=tmp[i-1])
		{
			now++;
			mymap[tmp[i]]=now;
			id[now]=tmp[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[mymap[l[i]]]+=1;
		a[mymap[r[i]+1]]-=1;
	}
	for(int i=1;i<=now;i++)
	{
		a[i]+=a[i-1];
	}
	for(int i=1;i<now;i++)
	{
		num[a[i]]+=id[i+1]-id[i];
	}
	printf("%lld",num[1]);
	for(int i=2;i<=n;i++)
	printf(" %lld",num[i]);
	cout<<endl;
	return 0;
}
