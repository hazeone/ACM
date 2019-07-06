#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 2147483647
#define fa(x) node[x].fa
int n,m,nxt[500000],sk[500000],top;
struct pp
{
	int fa,ch[2],sz,lazy;
}node[500000];
int G(int x,int y)
{
	if(x+y>n)return n+1;
	return x+y;
}
bool isroot(int p)
{
	return node[fa(p)].ch[0]!=p&&node[fa(p)].ch[1]!=p;
}
void maintain(int p)
{
	node[p].sz=node[node[p].ch[0]].sz+node[node[p].ch[1]].sz+1;
}
void debug()
{
	for(int i=1;i<=n+1;i++)
		cout<<i<<": "<<node[i].fa<<" "<<node[i].ch[0]<<" "<<node[i].ch[1]<<" "<<node[i].sz<<endl;
	getchar();
}
void rotate(int p)
{
	int t=(node[fa(p)].ch[0]!=p);
	node[fa(p)].ch[0^t]=node[p].ch[1^t];
	fa(node[p].ch[1^t])=fa(p);
	node[p].ch[1^t]=fa(p);
	if(!isroot(fa(p)))node[fa(fa(p))].ch[node[fa(fa(p))].ch[1]==fa(p)]=p;
	fa(p)=fa(fa(p));
	fa(node[p].ch[1^t])=p;
	maintain(node[p].ch[1^t]);
}
void pushdown(int p)
{
	if(node[p].lazy)
	{
		node[p].lazy=0;
		node[node[p].ch[0]].lazy^=1;
		node[node[p].ch[1]].lazy^=1;
		swap(node[p].ch[1],node[p].ch[0]);
	}
}
void splay(int p)
{
	sk[++top]=p;
	for(int i=p;!isroot(i);i=node[i].fa)
	{
		sk[++top]=node[i].fa;
	}
	while(top)
	{
		pushdown(sk[top--]);
	}
	for(;!isroot(p);rotate(p))
	{
		if(!isroot(fa(p)))
		rotate((node[fa(p)].ch[0]==p)==(node[fa(fa(p))].ch[0]==fa(p))?fa(p):p);
	}
	maintain(p);
}
void access(int p)
{
	int tmp=0;
	while(p)
	{
		splay(p);
		node[p].ch[1]=tmp;
		maintain(p);
		tmp=p;
		p=node[p].fa;
	}
}
void makeroot(int p)
{
	access(p);splay(p);node[p].lazy^=1;
}
void link(int a,int b)
{
	makeroot(a);node[a].fa=b;
}
void cut(int a,int b)
{
	makeroot(a);access(b);splay(b);
	if(node[b].ch[0]==a)node[a].fa=node[b].ch[0]=0;
	maintain(b);
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)node[i].sz=1;
	for(int i=1;i<=n;i++)
	{
		int c;
		scanf("%d",&c);
		nxt[i]=G(i,c);
		link(i,nxt[i]);
	}scanf("%d",&m);
	debug();
}
void work()
{
	int ord,x,y;
	while(m--)
	{
		scanf("%d%d",&ord,&x);
		x++;
		if(ord==1)
		{
			makeroot(x);access(n+1);splay(n+1);
			printf("%d\n",node[n+1].sz-1);
			debug();
		}
		else
		{
			scanf("%d",&y);
			cut(x,nxt[x]);
			nxt[x]=G(x,y);
			link(x,nxt[x]);
		}
	}
}
int main()
{
	init();
	work();
	return 0;
}
