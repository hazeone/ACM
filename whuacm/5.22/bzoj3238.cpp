#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int M=26;
#define LL long long

char s[N];
int n;
struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],endpos[N*2],v[N*2],b[N*2];
	LL pos[N],ans,mnode[N*2];
	sam()
	{
		last=cnt=1;
	}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		mnode[last]=1;
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
				mnode[nq]=0;
				mx[nq]=mx[p]+1;
				memcpy(trans[nq],trans[q],sizeof(trans[q]));
				link[nq]=link[q];
				link[np]=link[q]=nq;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
			}
		}
	}
	void slove()
	{
	/* 相当于容斥原理，先统计子树，再把重复的删掉
	    void dfs(int x)
		{
			bool flag=true;LL t1,t2=0;
			for(int i=Last[x];i;i=e[i].next)
			{
				flag=false;
				int y=e[i].y;
				dfs(y);f[x]+=f[y];t2+=(f[y]*(f[y]-1LL)/2LL);
			}
			if(!flag)
			{
				t1=f[x]*(f[x]-1LL)/2LL-t2;
				t1*=(mx[x]*2LL);
				ans-=t1;
			}
		}
    * */
		ans=0;
		for(int i=cnt;i>=1;i--)
		{
			int t=pos[i];
			ans+=(LL)mx[link[t]]*(LL)endpos[t]*mnode[link[t]];//mnode 维护已经和当前根节点联通的点的数量 与endpos相乘就相当于增加的通过根节点的路径数量
			mnode[link[t]]+=endpos[t];
		}
		printf("%lld\n",(LL)(n+1)*(LL)n/2*(LL)(n-1)-2*ans);
	}
	void getendpos()
	{
		for (int i=1;i<=cnt;i++) v[mx[i]]++;
		for (int i=1;i<=n;i++) v[i]+=v[i-1];
		for (int i=1;i<=cnt;i++) pos[v[mx[i]]--]=i;
		for (int i=1;i<=cnt;i++) endpos[i]=mnode[i];
		for (int i=cnt;i;i--){
			int t=pos[i];
			endpos[link[t]]+=endpos[t];
		}
	}
}SAM;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)SAM.add(s[n-i-1]-'a');
	SAM.getendpos();
	SAM.slove();
	return 0;
}
