#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+10;
const LL mod=1e9+7;
int n,m;
struct point
{
	int a,b;
}e[N];
int deg[N],sumn[N],sume[N];
void clr()
{
	int x=max(n,m)+10;
	for(int i=0;i<=x;i++)
	deg[i]=sumn[i]=sume[i]=0;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		clr();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&e[i].a,&e[i].b);
			deg[e[i].a]++;
			deg[e[i].b]++;
		}
		int top=N;
		for(int i=1;i<=m;i++)
		{
			sume[min(deg[e[i].a],deg[e[i].b])]++;
			top=min(top,max(deg[e[i].a],deg[e[i].b]));
		}
		for(int i=1;i<=n;i++)
		sumn[deg[i]]++;
		for(int i=n-1;i>=1;i--)
		{
			sume[i-1]+=sume[i];
			sumn[i-1]+=sumn[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			cout<<"e "<<i<<" "<<sume[i]<<endl;
		}cout<<"********"<<endl;
		for(int i=1;i<=n-1;i++)
		{
			cout<<"n "<<i<<" "<<sumn[i]<<endl;
		}
		LL ans=0;
		for(int k=1;k<=top;k++)
		{
			LL tn=sumn[k],te=sume[k];
			if(te*2==tn*(tn-1))
			{
				cout<<te<<" "<<tn<<" "<<k<<endl;
				ans=1;
				for(int i=1;i<=n;i++)
				{
					if((deg[i]>=k&&deg[i]==tn-1)||(deg[i]<k&&deg[i]==tn))
					//if((deg[i]>=k&&deg[i]==tn-1))
					ans++;
				}
				break;
			}
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}
