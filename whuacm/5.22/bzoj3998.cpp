#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int M=26;

#define LL long long

char s[N];
int n,T,k;

struct SAM
{
	int trans[N*2][M],mx[N*2],link[N*2],val[N*2],sum[N*2],pos[N*2],v[N*2];
	int cnt,last;
	SAM(){cnt=last=1;}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		val[np]=1;
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
	void pre()
	{
		for(int i=1;i<=cnt;i++)v[mx[i]]++;
		for(int i=1;i<=n;i++)v[i]+=v[i-1];
		for(int i=cnt;i>=0;i--)pos[v[mx[i]]--]=i;
		for(int i=cnt;i>=0;i--)
		{
			int t=pos[i];
			if(T==0)
			val[t]=1;
			else val[link[t]]+=val[t];
		}
		val[1]=0;
		for(int i=cnt;i>=0;i--)
		{
			int t=pos[i];sum[t]=val[t];
			for(int j=0;j<26;j++)
			sum[t]+=sum[trans[t][j]];
		}
		for(int i=0;i<=cnt;i++)
		cout<<i<<": "<<val[i]<<" "<<sum[i]<<endl;
	}
	void dfs(int p,int K)
	{
		if(K<=val[p])return;
		K-=val[p];
		for(int i=0;i<26;i++)
		{
			int t=trans[p][i];
			if(t)
			{
				if(K<=sum[t])
				{
					printf("%c",i+'a');
					dfs(t,K);
					return;
				}
				K-=sum[t];
			}
		}
	}
}sam;
int main()
{
	scanf("%s",s);
	scanf("%d%d",&T,&k);
	n=strlen(s);
	for(int i=0;i<n;i++)sam.add(s[i]-'a');
	sam.pre();
	if(sam.sum[1]<k)puts("-1");
	else sam.dfs(1,k);
	return 0;
}
