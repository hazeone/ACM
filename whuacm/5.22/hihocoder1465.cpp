#include<bits/stdc++.h>
using namespace std;

const int N=400010;
const int M=26;
#define LL long long

char s[N];
int n;
struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],mn[N*2],mnode[N*2],endpos[N*2],son[N*2],vis[N*2],ans;
	sam(){last=cnt=1;}

	void add(int c)
	{
		int p=last,np=last=++cnt;
		mnode[last]=1;
		mx[np]=mx[p]+1;//
		mn[np]=-1;
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];
		if(!p){
			link[np]=1;
			mn[np]=1;
		}
		else
		{
			int q=trans[p][c];
			if(mx[p]+1==mx[q])
			{
				link[np]=q;
				mn[np]=mx[q]+1;
			}
			else
			{
				int nq=++cnt;
				mnode[nq]=0;
				mx[nq]=mx[p]+1;
				memcpy(trans[nq],trans[q],sizeof(trans[q]));
				link[nq]=link[q];
				link[np]=link[q]=nq;
				mn[q]=mx[nq]+1;
				mn[np]=mx[nq]+1;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
				mn[nq]=mx[link[nq]]+1;
			}
		}
	}
	void slove()
	{
		scanf("%s",s);
		n=strlen(s);
		for(int i=n;i<2*n-1;i++)
		s[i]=s[i-n];
		int nn=n;
		n=2*n-1;
		int u=1,l=0;
		for(int i=0;i<=cnt;i++)vis[i]=0;
		ans=0;


		for(int i=0;i<n;i++)
		{
			int c=s[i]-'a';
			while(u!=1&&trans[u][c]==0)
			{
				u=link[u];
				l=mx[u];
			}
			if(trans[u][c])
			u=trans[u][c],l++;
			else u=1,l=0;
			if(l>nn)
				while(mx[link[u]]>=nn&&link[u]!=1){u=link[u],l=mx[u];}
			if(l>=nn&&!vis[u])
			{
				vis[u]=1;
				ans+=endpos[u];
			}
		}

		printf("%d\n",ans);
	}
	void getendpos()
	{
		for(int i=1;i<=cnt;i++)son[link[i]]++;
		queue<int> Q;
		for(int i = 1; i <= cnt; i++)
		if(son[i] == 0) Q.push(i), endpos[i] = 1;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			if(x == 0) continue;
			int y = link[x];
			son[y]--;
			endpos[y] += endpos[x];
			if(son[y] == 0){
				if(mnode[y]) endpos[y]++;
				Q.push(y);
			}
		}
	}
}SAM;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)SAM.add(s[i]-'a');
	SAM.getendpos();
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)SAM.slove();
	return 0;
}
