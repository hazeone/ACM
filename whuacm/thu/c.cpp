#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N=5e5+10;
LL inf=1e9+7;
int n1,n2,n3;
LL d;
LL a[N],b[N],c[N],dd[N],ddd[N];
LL lb[N],rb[N],lc[N],rc[N],lbc[N],rbc[N];
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,LL p)
{
	for(;x<=n3;x+=lowbit(x))
	dd[x]+=p;
}
LL get(int x)
{
	if(x<0)return 0;
	LL re=0;
	for(;x;x-=lowbit(x))
	{
		re+=dd[x];
	}
	return re;
}
void add1(int x,LL p)
{
	for(;x<=n3;x+=lowbit(x))
	ddd[x]+=p;
}
LL get1(int x)
{
	if(x<0)return 0;
	LL re=0;
	for(;x;x-=lowbit(x))
	{
		re+=ddd[x];
	}
	return re;
}
inline bool check(LL p,int k,LL z[])
{
	return z[k]<=p+d&&z[k]>=p-d;
}
int main()
{
	inf=inf*inf;
	while(cin>>d>>n1>>n2>>n3)
	{
		for(int i=1;i<=n1;i++) a[i]=read();
		for(int i=1;i<=n2;i++) b[i]=read();
		for(int i=1;i<=n3;i++) c[i]=read();
		for(int i=0;i<=n3;i++) ddd[i]=dd[i]=0;
		sort(a+1,a+1+n1);
		sort(b+1,b+1+n2);
		sort(c+1,c+1+n3);

		b[0]=c[0]=a[0]=-inf;
		b[n2+1]=c[n3+1]=a[n1+1]=inf;
		for(int i=1;i<=n1;i++)
		{
			LL t=a[i]-d,s=a[i]+d;
			lb[i]=lb[i-1];
			rb[i]=rb[i-1];
			//cout<<t<<" "<<s<<endl;
			while(b[lb[i]]<t&&lb[i]<n2)
			lb[i]++;
			while(b[rb[i]+1]<=s&&rb[i]+1<=n2)
			rb[i]++;
			lc[i]=lc[i-1];
			rc[i]=rc[i-1];
			while(c[lc[i]]<t&&lc[i]<n3)
			lc[i]++;
			while(c[rc[i]+1]<=s&&rc[i]+1<=n3)
			rc[i]++;
		}
		for(int i=1;i<=n2;i++)
		{
			LL t=b[i]-d,s=b[i]+d;
			lbc[i]=lbc[i-1];
			rbc[i]=rbc[i-1];
			while(c[lbc[i]]<t&&lbc[i]<n3)
			lbc[i]++;
			while(c[rbc[i]+1]<=s&&rbc[i]+1<=n3)
			rbc[i]++;
		}
		LL ans=0;
		int lastl=0,lastr=0;
		lbc[0]=0;
		rbc[0]=-1;/*
		for(int i=1;i<=3;i++)
		{
			cout<<"("<<lb[i]<<","<<rb[i]<<") ";
		}cout<<endl;
		for(int i=1;i<=3;i++)
		{
			cout<<"("<<lc[i]<<","<<rc[i]<<") ";
		}cout<<endl;
		for(int i=1;i<=3;i++)
		{
			cout<<"("<<lbc[i]<<","<<rbc[i]<<") ";
		}cout<<endl;*/
		for(int i=1;i<=n1;i++)
		{
			if(lb[i]>rb[i])continue;
			while(lastl<lb[i])
			{
				if(lbc[lastl]<=rbc[lastl]&&check(b[lastl],lbc[lastl],c)&&check(b[lastl],rbc[lastl],c))
				{
					//cout<<"del"<<" "<<lbc[lastl]<<" "<<rbc[lastl]<<endl;
					int tl=lbc[lastl],tr=rbc[lastl]+1;
					add(tl,-1);
					add1(tl,-tl);
					add(tr,1);
					add1(tr,tr);
				}
				lastl++;
			}
			while(lastr<rb[i])
			{
				lastr++;
				if(lbc[lastr]<=rbc[lastr]&&check(b[lastr],lbc[lastr],c)&&check(b[lastr],rbc[lastr],c))
				{
					//cout<<"add"<<" "<<lbc[lastr]<<" "<<rbc[lastr]<<endl;
					int tl=lbc[lastr],tr=rbc[lastr]+1;
					add(tl,1);
					add1(tl,tl);
					add(tr,-1);
					add1(tr,-tr);
				}
			}
			LL tl=lc[i]-1,tr=rc[i];
			if(tl<tr&&check(a[i],lc[i],c)&&check(a[i],tr,c))
			{
				LL sumr=(tr+1)*get(tr)-get1(tr);
				LL suml=(tl+1)*get(tl)-get1(tl);
				ans+=sumr-suml;
				//cout<<"qes "<<tl+1<<" "<<tr<<" "<<ans<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
