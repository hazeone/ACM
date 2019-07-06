#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=300010;
int n,x,y;
int tot,g[N],f[N];
LL ans;
struct point
{
	int to,next;
}e[N*2];
void clr()
{
	tot=0;
	for(int i=0;i<=n;i++)
	g[i]=f[i]=0;
}
void add(int a,int b)
{
	e[++tot].to=b;
	e[tot].next=g[a];
	g[a]=tot;
}
void dfs(int now,int pre)
{
	f[now]=1;
	for(int tmp=g[now];tmp;tmp=e[tmp].next)
	{
		if(e[tmp].to==pre)continue;
		dfs(e[tmp].to,now);
		f[now]+=f[e[tmp].to];
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		clr();
		scanf("%d%d",&x,&y);
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		dfs(x,0);
		ans=(LL)n*(LL)(n-1);
		LL ans1=f[y];
		dfs(y,0);
		LL ans2=f[x];
		printf("%lld\n",ans-ans1*ans2);
	}
    return 0;
}
