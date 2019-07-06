#include<bits/stdc++.h>
using namespace std;

const int N=2000050;
const int M=11;
#define LL long long

char s[N];
int n,m;
LL mod=1e9+7;

struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],mn[N*2],mnode[N*2],endpos[N*2],son[N*2],in[N*2],visable[N*2];
	LL sum[N*2],num[N*2];
	sam()
	{
		last=cnt=1;
	}
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
		LL ans=0;
		num[1]=1;sum[1]=0;
		visable[1]=in[1]=1;
		queue <int> Q;
		Q.push(1);
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();
			for(int i=0;i<=9;i++)
			{
				if(trans[x][i])
				{
					int y=trans[x][i];
					son[y]++;
					visable[y]=1;
					if(in[y]==0)in[y]=1,Q.push(y);
				}
			}
		}
		for(int i=1;i<=cnt;i++)
		if(visable[i]&&son[i]==0)Q.push(i);
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();
			for(int i=0;i<=9;i++)
			{
				if(trans[x][i])
				{
					int y=trans[x][i];
					son[y]--;
					num[y]=(num[x]+num[y])%mod;
					sum[y]=((LL)10*sum[x]+sum[y]+(LL)i*num[x])%mod;
					if(son[y]==0)Q.push(y);
				}
			}
		}
		for(int i=1;i<=cnt;i++)
		if(visable[i])
		ans=(ans+sum[i])%mod;
		printf("%lld\n",ans);
	}
}SAM;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		n=strlen(s);
		if(i>1)SAM.add(10);
		for(int i=0;i<n;i++)SAM.add(s[i]-'0');
	}
	SAM.slove();
	return 0;
}
