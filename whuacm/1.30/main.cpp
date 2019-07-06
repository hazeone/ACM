#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
//#define mmt(a,v) memset(a,v,sizeof(a))
#define tra(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
const int N=200000+5;
const int M=2000000+5;
//const int INF = 1000100;
int par[M],ch[M][26],siz[2][M],len[M],root,sz,last,f[M];
void init(){last=root=sz=1;}
void extend(int x){
	int p=last,np=++sz;
	len[np]=len[p]+1;
	for(;p&&!ch[p][x];p=par[p])ch[p][x]=np;
	if(!p)par[np]=root;
	else{
		int q=ch[p][x];
		if(len[q]==len[p]+1)par[np]=q;
		else{
			int nq=++sz;
			len[nq]=len[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			par[nq]=par[q];
			par[q]=par[np]=nq;
			for(;p&&ch[p][x]==q;p=par[p])ch[p][x]=nq;
		}
	}
	last=np;
}
int deg[M];
int q[M];
void toposort(){
	rep(i,1,sz)deg[par[i]]++;
	int head=0,tail=0;
	rep(i,1,sz)if(!deg[i])q[++tail]=i,f[i]=0;
	while(head<tail){
		int u=q[++head];
		deg[par[u]]--;
		if(f[u]==0)
			f[par[u]]=1;
		if(!deg[par[u]])q[++tail]=par[u];
	}
}
char s[N];
int main(){
	//freopen("a.in","r",stdin);
	while(scanf("%s",s+1)!=EOF)
	{
		int n=strlen(s+1);
		init();
		int p=root;
		rep(i,1,n){
			extend(s[i]-'a');
			p=ch[p][s[i]-'a'];
		}
		for(int i=1;i<=sz;i++)
			f[i]=0;
		toposort();
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			int v=root;
			int m=strlen(s+1);
			for(int j=1;j<=m;j++)
				v=ch[v][s[j]-'a'];
			 ans^=f[v];
		}
		if(ans==1)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}
