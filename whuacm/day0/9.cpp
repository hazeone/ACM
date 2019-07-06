#include<bits/stdc++.h>
using namespace std;

const int N=300010;
const int M=5;
#define LL long long

char s[N];
int n,m,cnt[4],sum,sb[10],fuck,bl[N];
struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2];
	sam()
	{
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
	void clr()
	{
		cnt=last=1;
		memset(link,0,sizeof(link));
		memset(mx,0,sizeof(link));
		memset(trans,0,sizeof(trans));
	}
	void slove()
	{
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			ans=ans+mx[i]-mx[link[i]];
		}
		LL tmp=1;
		for(int i=1;i<=sum;i++)tmp*=i;
		if(sum==3)ans+=fuck*3;
		ans/=tmp;
		printf("%lld\n",ans);
	}
}SAM;
void dfs(int x)
{
	if(x==4)
	{
		int last=1;
		for(int p=1;p<=n;p++)
		{
			int t=s[p]-'a';
			if(t==0)
			last=SAM.add(sb[1],last);
			if(t==1)
			last=SAM.add(sb[2],last);
			if(t==2)
			last=SAM.add(sb[3],last);
		}
		return;
	}
	if(cnt[x-1]==0)
	{
		sb[x]=0;
		dfs(x+1);
		return;
	}
	for(int i=1;i<4;i++)
	{
		if(cnt[i-1]==0)
		continue;
		int p=1;
		for(int j=1;j<x;j++)
		{
			if(sb[j]==i)
			{
				p=0;
				break;
			}
		}
		if(p==1)
		{
			sb[x]=i;
			dfs(x+1);
		}
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		SAM.clr();
		cnt[0]=cnt[1]=cnt[2]=0;
		sum=0;
		fuck=1;
		memset(bl,0,sizeof(bl));
		//memset(cl,0,sizeof(cl));
		scanf("%s",s+1);
		s[0]='!';
		for(int i=1;i<=n;i++)
		{
			if(cnt[s[i]-'a']==0)
			{
				sum++;
				cnt[s[i]-'a']=1;
			}
			//int p=s[i]-'a';
			if(s[i]==s[i-1])
			{
				bl[i]=bl[i-1]+1;
				fuck=max(fuck,bl[i]);
			}
			else
			{
				bl[i]=1;
			}
		}
		dfs(1);
		SAM.slove();
	}
	return 0;
}
