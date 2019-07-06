#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
long long a[1000000],b[1000000];
bool cmp(int x,int y)
{
	return x>y;
}
bool check(int k)
{
	if(k<=1)return true;
	int begin=m-k+1,sk=0;
	int leve=1,pos=begin,ptou=2;
	long long sum=a[1];
	if(b[begin]<1)return false;
	while(pos<=m)
	{//cout<<pos<<endl;
		while(b[pos]==leve)
		{
			sum--;
			pos++;
			if(sum<0)return false;
			if(sum>=0&&pos>m)return true;
			if(sum==0&&b[pos]==leve)return false;
		}
		//cout<<"????"<<endl;
		if(m-pos+1<=sum)return true;
		sk=sum;
		while(ptou<=n&&sk>0)
		{
			sum+=a[ptou]-1;
			sk--;
			ptou++;
		}
		leve++;
		//if(ptou>n)return true;
	}
	return true;
}
int main()
{
	freopen("J.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%lld",&b[i]);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m);
	int l=0,r=m,mid;
	//cout<<check(5)<<endl;
	//cout<<"!!!!!!!!"<<endl;
	while(l<r)
	{
		mid=(l+r)>>1;
		//cout<<mid<<endl;
		if(check(mid))
		l=mid+1;
		else r=mid;
	}
	if(!check(l))
	l--;
	printf("%d\n",l);
	return 0;
}
