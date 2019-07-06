#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
int sumz,d[200000],len,n,a[200000],T;
int find(int l,int r,int x)
{
	int mid=(l+r)>>1;
	while(l<=r)
	{
		if(d[mid]>=x)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
		mid=(l+r)>>1;
	}
	return l;
}
int main()
{
	int ww=clock();
	freopen("1010.in","r",stdin);
	cin>>T;
	for(int p=1;p<=T;p++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sumz=0;
		len=1;
		d[1]=a[1];
		if(a[1]==0)sumz++;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==0)
			{
				sumz++;
				len++;
				for(int j=len;j>sumz;j--)
				{
					d[j]=d[j-1]+1;
				}
			}
			else
			{
				int pos=find(sumz+1,len,a[i]);
				d[pos]=a[i];
				if(pos>len)len++;
			}
		}
		cout<<"Case #"<<p<<": "<<len<<endl;
	}
	int ee=clock();
	cout<<ee-ww<<endl;
	return 0;
}
