#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int M=10;
#define LL long long

int s[N],cnt[N],tot,g[N];
int n,m;
struct point
{
	int to,next;
}e[N];
struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],mn[N*2];
	sam()
	{
		last=cnt=1;
	}
	int add(int c,int begin)
	{
		int p=begin,np=++cnt;
		mx[np]=mx[p]+1;//
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];
		if(!p)link[np]=1;
		else
		{
			int q=trans[p][c];
			if(mx[p]+1==mx[q])
			link[np]=q;
			else
			{
				int nq=++cnt;
				mx[nq]=mx[p]+1;
				memcpy(trans[nq],trans[q],sizeof(trans[q]));
				link[nq]=link[q];
				link[np]=link[q]=nq;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
			}
		}
		return np;
	}
	void slove()
	{
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			ans=ans+mx[i]-mx[link[i]];
		}
		printf("%lld\n",ans);
	}
}SAM;
void addedge(int x,int y){e[++tot].to=y;e[tot].next=g[x];g[x]=tot;}
void dfs(int x,int pre,int begin)
{
	int t=SAM.add(s[x],begin);
	for(int tmp=g[x];tmp;tmp=e[tmp].next)
	{
		if(e[tmp].to!=pre)
		dfs(e[tmp].to,x,t);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			cnt[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			cnt[x]++;
			cnt[y]++;
			addedge(x,y);
			addedge(y,x);
		}
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==1)
			dfs(i,0,1);
		}
	SAM.slove();
	return 0;
}

