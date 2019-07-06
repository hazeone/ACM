/*
求n个串的最长公共子串
*/
#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int M=26;
#define LL long long

char s[N];
int n;

struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],mn[N*2],v[N],pos[N*2],ans,cl[N*2];
	sam(){last=cnt=1;}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		mx[np]=mx[p]+1;//
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];
		if(!p)link[np]=1;
		else
		{
			int q=trans[p][c];
			if(mx[p]+1==mx[q])
			{
				link[np]=q;
			}
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
	}
	void slove()
	{
		for(int i=1;i<=cnt;i++)
		mn[i]=1e9;
		while(~scanf("%s",s))
		{
			for(int i=1;i<=cnt;i++)
			cl[i]=0;
			n=strlen(s);
			int p=1,tmp=0;
			for(int i=0;i<n;i++)
			{
				int c=s[i]-'a';
				if(trans[p][c])
				{
					p=trans[p][c];
					tmp++;
					cl[p]=max(cl[p],tmp);
					continue;
				}
				while(!trans[p][c]&&p!=1)p=link[p];
				if(trans[p][c])
				{
					tmp=mx[p]+1;
					p=trans[p][c];
					cl[p]=max(cl[p],tmp);
				}
				else p=1,tmp=0;
			}
			for (int i=cnt;i>=1;i--)
			{
				int t=pos[i];
				mn[t]=min(mn[t],cl[t]);
				if (cl[t]&&link[t]) cl[link[t]]=mx[link[t]];
			}
		}
		ans=0;
		for(int i=1;i<=cnt;i++)
		ans=max(ans,mn[i]);
		printf("%d\n",ans);
	}
	void pre()
	{
		for(int i=1;i<=cnt;i++)v[mx[i]]++;
		for(int i=1;i<=n;i++)v[i]+=v[i-1];
		for(int i=1;i<=cnt;i++)pos[v[mx[i]]--]=i;
	}
}SAM;
int main()
{
	freopen("tmp.in","r",stdin);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)SAM.add(s[i]-'a');
	SAM.pre();
	SAM.slove();
	return 0;
}
