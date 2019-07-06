#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
struct poit
{
	int l,r,flag;
	long long sum;
}t[400001];
long long f[81];
int find(long long x)
{
	int p=0,q=80;
	while(p<q)
	{
		int mid=(p+q)>>1;
		if(f[mid]<x)
		{
			p=mid+1;
		}
		else 
		{
			q=mid;
		}
	}
	return p;
}
void build(int o,int x,int y)
{
	//cout<<o<<" "<<x<<" "<<y<<endl;
	t[o].l=x;t[o].r=y;
	t[o].sum=t[o].flag=0;
	if(x!=y)
	{
		build(o<<1,x,(x+y)>>1);
		build(o<<1|1,((x+y)>>1)+1,y);
	}
}
void pushup(int o)
{
	t[o].sum=t[o<<1|1].sum+t[o<<1].sum;
	t[o].flag=(t[o<<1].flag&&t[o<<1|1].flag);
}
void change(int o,int x,int y)
{
	if(t[o].flag&&t[o].l==x&&t[o].r==y)return;
	if(t[o].l==t[o].r)
	{
		int pos=find(t[o].sum);
		t[o].flag=1;
		if(f[pos]!=t[o].sum)
		{
			if(pos>=1)
			{
				if(t[o].sum-f[pos-1]<=f[pos]-t[o].sum)
			    {
				   t[o].sum=f[pos-1];
			    }
			    else t[o].sum=f[pos];
			}
			else t[o].sum=f[pos]; 
		}
		return;
	}
	int mid=(t[o].l+t[o].r)>>1;
	if(y<=mid)change(o<<1,x,y);
	else if(x>mid)change(o<<1|1,x,y);
	else
	{
		change(o<<1,x,mid);
		change(o<<1|1,mid+1,y);
	}
	pushup(o);
}
void add(int o,int k,int ad)
{
	if(t[o].l==t[o].r)
	{
		t[o].sum+=ad;
		int pos=find(t[o].sum);
		t[o].flag=(f[pos]==t[o].sum);
		return;
	}
	int mid=(t[o].l+t[o].r)>>1;
	t[o].flag=0;
	if(k<=mid)
	add(o<<1,k,ad);
	else
	add(o<<1|1,k,ad);
	pushup(o);
}
long long getsum(int o,int x,int y)
{
	if(t[o].l==x&&t[o].r==y)return t[o].sum;
	int mid=(t[o].l+t[o].r)>>1;
	if(y<=mid)return getsum(o<<1,x,y);
	else if(x>mid)return getsum(o<<1|1,x,y);
	else return getsum(o<<1,x,mid)+getsum(o<<1|1,mid+1,y);
}
void debug()
{
	cout<<endl;
	for(int i=1;i<=9;i++)
	{
		cout<<i<<" "<<t[i].l<<" "<<t[i].r<<" "<<t[i].sum<<" "<<t[i].flag<<endl;
	}
}
int main()
{
	freopen("C.in","r",stdin);
	///freopen("C.out","w",stdout);
	f[0]=f[1]=1;
	for(int i=2;i<=80;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	//cout<<find(0)<<find(1)<<find(3)<<find(4)<<endl;
	//cout<<f[80]<<endl;
	//cout<<find(-111111111);
	while(cin>>n>>m)
	{
		build(1,1,n);//cout<<"C++++++++++++";
		int q,x,y;
		while(m--)
		{
			scanf("%d%d%d",&q,&x,&y);
			if(q==1)
			{
				add(1,x,y);//debug();
			}
			if(q==2)
			{
				cout<<getsum(1,x,y)<<endl;//debug();
			}
			if(q==3)
			{
				change(1,x,y);//debug();
			}
		}
	}
	return 0;
}
