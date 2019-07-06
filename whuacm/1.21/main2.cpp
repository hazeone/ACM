#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define LL long long 
const int mod=77877;
int nxt[mod],head[mod],tot,key[mod],val[mod];
LL ans;
LL qpow(LL a,LL b,LL c)
{
	LL re=1;
	for(;b;a=a*a%c,b=b>>1)
	if(b&1)re=re*a%c;
	return re;
}
void insert(int k,int v)
{
	int tmp=k%mod;
	tot++;
	key[tot]=k;val[tot]=v;
	nxt[tot]=head[tmp];
	head[tmp]=tot;
}
int find(int x)
{
	for(int tmp=head[x%mod];tmp;tmp=nxt[tmp])
	{
		if(key[tmp]==x)return val[tmp];
	}
	return -1;
}
int BSGS(LL a,LL b, LL p)
{
	tot=0;memset(head,0,sizeof(head));
	LL m=ceil(sqrt(p));
	if(b==1){ans=0;return 1;}
	LL x=b,y=qpow(a,m,p);
	for(int i=0;i<m;i++)
	{
		insert(x,i);
		x=x*a%p;
	}
	x=y;
	for(int i=1;i<=m;i++)
	{
		int j=find(x);
		if(j!=-1)
		{
			ans=i*m-j;
			return 1;
		}
		x=x*y%p;	
	}
	return -1;
}
int main()
{
	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout);
	LL n,b,p;
	while(~scanf("%lld%lld%lld",&p,&b,&n))
	{
		if(BSGS(b,n,p)==-1)
		printf("no solution\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
