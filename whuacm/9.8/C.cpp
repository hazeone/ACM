#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
#define inf 1000000007
int n;
struct point
{
	double s,t,u,v;
	double k,b;
	
}seg[3000];
bool cmp(point A,point B)
{
	return A.k<B.k;
}
long long ans=0;
double dis[5000000];
double getdis(point A,point B)
{
	return fabs(A.b-B.b)/sqrt(1+A.k*A.k);
}
int main()
{
	freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>seg[i].s>>seg[i].t>>seg[i].u>>seg[i].v;
		if(seg[i].s==seg[i].u)
		{
			seg[i].k=inf;
		}
		else if(seg[i].t==seg[i].v)
		{
			seg[i].k=0;
			seg[i].b=seg[i].v;
		}
		else
		{
			seg[i].k=(seg[i].v-seg[i].t)/(seg[i].u-seg[i].s);
			seg[i].b=seg[i].t-seg[i].k*seg[i].s;
		}
	}
	sort(seg+1,seg+1+n,cmp);
	/*for(int i=1;i<=n;i++)
	{
		cout<<seg[i].s<<" "<<seg[i].t<<" "<<seg[i].u<<" "<<seg[i].v<<" "<<seg[i].k<<" "<<seg[i].b<<endl;
	}*/
	//cout<<getdis(seg[1],seg[2]);
	int l=1,r=1,tot=0,r1,l1;
	double tmpk;
	while(1)
	{
		if(seg[l].k>0)break;
		tot=0;r=l+1;
		while(seg[l].k==seg[r].k)r++;r--;
		if(l==r)
		{
			l++;
			if(l>n)break;
			continue;
		}
		tmpk=seg[l].k;
		//cout<<tmpk<<endl;
		for(int i=l;i<r;i++)
		{
			for(int j=i+1;j<=r;j++)
			{
				dis[++tot]=getdis(seg[i],seg[j]);
			}
		}
		//sort(dis+1,dis+1+tot);
		//for(int i=1;i<=tot;i++)
		//cout<<dis[i]<<" ";cout<<endl;
		if(seg[l].k==0)
		{
			for(int i=r+1;i<=n;i++)
			{
				if(seg[i].k==inf)
				{
					l1=i;
					break;
				}
			}
			r1=n;
			//cout<<l1<<" "<<r1<<endl;
			//if(l1==r1)break;
			for(int i=l1;i<r1;i++)
			for(int j=i+1;j<=r1;j++)
			{
				double tmpd=abs(seg[i].s-seg[j].s);
				//cout<<seg[i].s<<" "<<seg[i].t<<" "<<seg[i].u<<" "<<seg[i].v<<" "<<seg[i].k<<" "<<seg[i].b<<endl;
				//cout<<seg[j].s<<" "<<seg[j].t<<" "<<seg[j].u<<" "<<seg[j].v<<" "<<seg[j].k<<" "<<seg[j].b<<endl;
				//cout<<tmpd<<endl;
				for(int lala=1;lala<=tot;lala++)
				{
					if(tmpd==dis[lala])
					ans++;
				}
			}
			break;
		} 
		for(int i=r+1;i<=n;i++)
		{
			if(seg[i].k*tmpk==-1.0)
			{
				r1=l1=i;
				break;
			}
		}
		for(int i=l1+1;i<=n;i++)
		{
			if(seg[i].k==seg[l1].k)
			r1=i;
			else break;
		}
		if(l1==r1)
		{
			l++;
			if(l>n)break;
			continue;
		}//cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
		for(int i=l1;i<r1;i++)
		{
			for(int j=i+1;j<=r1;j++)
			{
				double tmpd=getdis(seg[i],seg[j]);
				for(int lala=1;lala<=tot;lala++)
				{
					if(tmpd==dis[lala])
					ans++;
				}
			}
		}
		l++;
		if(l>n)break;
	}
	cout<<ans<<endl;
	return 0;
}
