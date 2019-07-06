#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define INF 2000000000
#define V 100008
#define E 300008
#define clr(x,v) memset(x,v,sizeof(x))
int cnt,n,m,q;
int ui[100],vi[100],wi[100],f[100100],l[100100][20],dep[100100],s[100100];
int id[V],rk[108],num,dist[108][V];
struct edge{
    int u,w;
};
vector <edge> e[100100];
struct line{
    int u,v,w,nt;
}eg[E];
int lt[V],sum;
void add(int u,int v,int w){
    eg[++sum]=(line){u,v,w,lt[u]};
    lt[u]=sum;
}
int father(int x)
{
    if(f[x]==x)return x;
    f[x]=father(f[x]);
    return f[x];
}

void dfs(int x,int fa,int sum)
{
    l[x][0]=fa;
    s[x]=sum;
    dep[x]=dep[fa]+1;
    for(int i = 0;i < e[x].size();i++)
    {
        int u=e[x][i].u;
        if(u!=fa)
        {
            dfs(u,x,sum+e[x][i].w);
        }
    }
}

int lca(int a,int b)
{
    if(dep[a]<dep[b])swap(a,b);
    int d=dep[a]-dep[b];
    for(int i = 0;i <= 18;i++)
        if(d&(1<<i))a=l[a][i];
    if(a==b)return a;
    for(int i = 18;i >= 0;i--)
        if(l[a][i]!=l[b][i])
        {
            a=l[a][i];
            b=l[b][i];
        }
    return l[a][0];
}
int dis(int x,int y){
    int p=lca(x,y);
    return s[x]+s[y]-s[p]*2;
}

int d[V],pd[V];
queue <int> Q;
void spfa(int s){
    for (int i=1;i<=n;i++){
        d[i]=INF;
        pd[i]=0;
    }
    d[s]=0; pd[s]=1; Q.push(s);
    while (!Q.empty()){
        int u=Q.front();
        Q.pop();
        for (int i=lt[u];i;i=eg[i].nt){
            int v=eg[i].v;
            if (d[u]+eg[i].w<d[v]){
                d[v]=d[u]+eg[i].w;
                if (!pd[v]){
                    pd[v]=1;
                    Q.push(v);
                }
            }
        }
        pd[u]=0;
    }
    for (int i=1;i<=n;i++) dist[id[s]][i]=d[i];
}
void work()
{
    for(int i = 1;i <= 18;i++)
        for(int j = 1;j <= n;j++)
            l[j][i]=l[l[j][i-1]][i-1];
    for (int i=1;i<=num;i++) spfa(rk[i]);
    while (q--){
        int u,v;
        scanf("%d%d",&u,&v);       
        int ans=dis(u,v);
        for (int i=1;i<=num;i++)
            ans=min(ans,dist[i][u]+dist[i][v]); 
        printf("%d\n",ans);
    }
}
int main()
{
	freopen("C.in","r",stdin);
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        clr(lt,0); sum=0;
        cnt=0; num=0;
        clr(id,0);
        printf("Case %d:\n",++cas);
        scanf("%d%d%d",&n,&m,&q);
        for(int i = 1;i <= n;i++)e[i].clear();
        for(int i = 1;i <= n;i++)f[i]=i;
        for(int i = 1;i <= m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
            if(father(u)!=father(v))
            {
                f[father(u)]=father(v);
                e[u].push_back((edge){v,w});
                e[v].push_back((edge){u,w});
            }
            else
            {
                cnt++;
                ui[cnt]=u;
                vi[cnt]=v;
                wi[cnt]=w;
                if (!id[u]){
                    id[u]=++num;
                    rk[num]=u;
                }
                if (!id[v]){
                    id[v]=++num;
                    rk[num]=v;
                }
            }
        }
        dfs(1,0,0);
        work();
    }
    return 0;
}
