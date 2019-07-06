/*
输入格式
第一行一个整数 t，表示子任务编号.t∈{1,2}，如果 t=1 则表示处理无向图的情况，如果 t=2 则表示处理有向图的情况。

第二行两个整数 n,m 表示图的结点数和边数。

接下来 m 行中，第 i 行两个整数 vi,ui，表示第 i 条边（从 1 开始编号）。保证1≤vi,ui≤n。

如果 t=1 则表示 vi 到 ui 有一条无向边。
如果 t=2 则表示 vi 到 ui 有一条有向边。
图中可能有重边也可能有自环。

输出格式
如果不可以一笔画，输出一行 “NO”。
否则，输出一行 “YES”，接下来一行输出一组方案。
如果 t=1，输出 m 个整数 p1,p2,…,pm。令 e=∣pi∣，那么 e 表示经过的第 i 条边的编号。如果 pi 为正数表示从 vi 走到 ui，否则表示从 ui 走到 vi。
如果 t=2，输出 m 个整数 p1,p2,…,pm。其中 pi 表示经过的第 i 条边的编号。*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;

struct node
{
    int to,next,w;
}e[M*2];

int n,m,tot,cnt;
int head[N],indeg[N],outdeg[N],ans[N];
bool vis[M*2];

void init()
{
    tot=2;
    memset(vis,false,sizeof(vis));
    memset(head,0,sizeof(head));
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
}
void addedge(int u,int v,int w){
    e[tot].to=v;
    e[tot].next=head[u];
    e[tot].w=w;
    head[u]=tot++;
}
//传说中的套圈法,输出欧拉回路路径
void dfs(int u)
{
    //这个引用好神奇啊，速度快了好多，学习了0 0
    //好像类似于网络流的cur优化(没学过网路流,瞎说的)
    //然后关于tot的处理也很巧妙
    for(int &j=head[u];j;j=e[j].next){
        node t=e[j];
        if(!vis[j>>1]){
            vis[j>>1]=true;
            dfs(t.to);
            ans[++cnt]=t.w;
        }
    }
}
int main()
{
    int t;
    scanf("%d%d%d",&t,&n,&m);
    init();
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b,i);
        indeg[b]++;
        outdeg[a]++;
        if(t==1)
            addedge(b,a,-i);
        else
            tot++;
    }
    bool flag=true;
    if(t==1)
    {
        for(int i=1;i<=n;i++)
        {
            if((indeg[i]+outdeg[i])%2)
            {
                flag=false;
                break;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]!=outdeg[i])
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
    {
        dfs(a);
        if(cnt!=m)
            puts("NO");
        else
        {
            puts("YES");
            for(int i=cnt;i>=1;i--)
            {
                if(i==1)
                    printf("%d\n",ans[i]);
                else
                    printf("%d ",ans[i]);
            }
        }
    }
    else puts("NO");
    return 0;
}
