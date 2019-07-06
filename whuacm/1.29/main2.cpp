#include<bits/stdc++.h>
using namespace std;
const int M = 1000100;
struct node
{
	int from,to,next;
}edge[M];
int n,m;
int ans,vv[M],in[M],in1[M];
int num,p[M],flag[M];
void add(int x,int y)
{
	num++;
	edge[num].from=x;
	edge[num].to=y;
	edge[num].next=p[x];
	p[x]=num;
}
void init()
{
	num=0;
	for(int i=0;i<=n;i++)
		in[i]=p[i]=flag[i]=0;
}
queue<int>q;
bool deal()
{
	for(int i=1;i<=n;i++)
		{in1[i]=in[i];vv[i]=0;}
	for(int i=1;i<=num;i++)
		if(flag[edge[i].from])
			in1[edge[i].to]--;
	while(!q.empty())
		q.pop();
	for(int i=1;i<=n;i++)
		if(in1[i]==0)
			{vv[i]=1;q.push(i);}
	while(!q.empty())
	{
		int k=q.front();vv[k]=0;
		q.pop();
		for(int i=p[k];i!=0;i=edge[i].next)
		{
			int v=edge[i].to;
			in1[v]--;
			if(in1[v]==0&&!vv[v])
				{
					q.push(v);
					vv[i]=1;
					}
		}
	}
	for(int i=1;i<=n;i++)
		if(in1[i]>0)
			return false;
	return true;
}
void dfs(int x,int k)
{
	if(x==n+1)
	{
		if(deal())
			ans=min(ans,k);
		return ;
	}
	if(k>ans)
		return ;
	dfs(x+1,k);
	flag[x]=1;
	dfs(x+1,k+1);
	flag[x]=0;
}
int main()
{
	int t;
	while(~scanf("%d",&t)){
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init();
		ans=n;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			in[y]++;
		}
		dfs(1,0);
		printf("%d\n",ans+n);
	}}
	return 0;
}
