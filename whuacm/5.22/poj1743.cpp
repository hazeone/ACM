#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=200010;
const int M=176;

#define LL long long

int a[N];
int n,T,k;

struct SAM
{
	int trans[N*2][M],mx[N*2],link[N*2],pos[N*2],v[N],mm[N*2],nn[N*2];
	int cnt,last;
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
	void clr()
	{
		for(int i=1;i<n;i++)a[i]=a[i+1]-a[i]+87;
		n--;
		cnt=last=1;
		for(int i=0;i<=n*2;i++)
		{
			for(int j=0;j<=175;j++)
			trans[i][j]=0;
			link[i]=mx[i]=pos[i]=0;
		}
	}
	void pre()
	{
		for(int i=0;i<=n;i++)v[i]=0;
		for(int i=1;i<=cnt;i++)v[mx[i]]++;
		for(int i=1;i<=n;i++)v[i]+=v[i-1];
		for(int i=1;i<=cnt;i++)pos[v[mx[i]]--]=i;
		for(int i=1;i<=cnt;i++)mm[i]=0,nn[i]=1e9;
		int p=1;
		for(int i=1;i<=n;i++)
		{
			p=trans[p][a[i]];
			mm[p]=nn[p]=i;
		}
		for(int i=cnt;i>=1;i--)
		{
			int t=pos[i];
			mm[link[t]]=max(mm[link[t]],mm[t]);
			nn[link[t]]=min(nn[link[t]],nn[t]);
		}
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			 if(mm[i]-nn[i]>=mx[i])
			 ans=max(ans,mx[i]);
		}
		ans++;
		if(ans<5)ans=0;
		printf("%d\n",ans);
		for(int i=1;i<=cnt;i++)
		cout<<i<<": "<<mm[i]<<" "<<nn[i]<<" "<<mx[i]<<endl;
	}
}sam;
int main()
{
	while(~scanf("%d",&n))
	{
		if(!n)break;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sam.clr();
		for(int i=1;i<=n;i++)sam.add(a[i]);
		sam.pre();
	}
	return 0;
}
/*
8
1 1 1 2 3 3 4 7
**/
