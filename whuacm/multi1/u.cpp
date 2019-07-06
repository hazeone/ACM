#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
const int M=200010;

struct node
{
    int to,next,w;
}e[M*2];

int n,m,tot,cnt;
int g[N],in_deg[N],out_deg[N],ans[N*2],p[M];
bool vis[M*2],v[N];

void clr()
{
    tot=2;
    memset(vis,false,sizeof(vis));
    memset(v,false,sizeof(v));
    memset(g,0,sizeof(g));
    memset(in_deg,0,sizeof(in_deg));
    memset(out_deg,0,sizeof(out_deg));
    memset(p,0,sizeof(p));
    memset(ans,0,sizeof(ans));
    cnt=0;
}

void addedge(int u,int v,int w){
    e[tot].to=v;
    e[tot].next=g[u];
    e[tot].w=w;
    g[u]=tot++;
}

void dfs(int u)
{
	v[u]=1;
    for(int &j=g[u];j;j=e[j].next)
	{
        node t=e[j];
        if(!vis[j>>1])
		{
            vis[j>>1]=true;
            dfs(t.to);
            ans[++cnt]=t.w;
        }
    }
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("a.out", "w", stdout);
    while(~scanf("%d%d",&n,&m))
	{
	    clr();
	    int a,b;
	    for(int i=1;i<=m;i++)
		{
	        scanf("%d%d",&a,&b);
	        addedge(a,b,i);
	        in_deg[b]++;
	        out_deg[a]++;
	        addedge(b,a,-i);
	    }
        for(int i=1;i<=n;i++)
		{
            if((in_deg[i]+out_deg[i])%2)
			{
                if(in_deg[i]%2)
                {
                	out_deg[i]++;
                	//a=i;b=n+1;
                	addedge(i,n+1,m+1);
                	addedge(n+1,i,-(m+1));
                }
                else
                {
                	in_deg[i]++;
                	b=n+1;a=i;
                	addedge(n+1,i,m+1);
                	addedge(i,n+1,-(m+1));
                }
            }
        }
        int tmp=0;
        for(int i=n+1;i>0;i--)
        if(!v[i])
        {
	        dfs(i);
	        ans[++cnt]=m+1;
		}
		for (int i = cnt; i >= 1; i --)
			printf("%d ", ans[i]);
		printf("\n");
		for(int i=cnt;i>=1;i--)
		{
			if(abs(ans[i])==m+1)continue;
			if(abs(ans[i])<=m&&abs(ans[i+1])>m)
			{
				p[++tmp]++;
			}
			else if(ans[i]<=m)
			{
				p[tmp]++;
			}
		}
		printf("%d",tmp);
		tmp=0;
		for(int i=cnt;i>=1;i--)
		{
			if(abs(ans[i])==m+1)continue;
			if(abs(ans[i])<=m&&abs(ans[i+1])>m)
			{
				tmp++;
				printf("\n%d %d",p[tmp],ans[i]);
			}
			else if(ans[i]<=m)
			{
				printf(" %d",ans[i]);
			}
		}
		cout<<endl;
	}
    return 0;
}
