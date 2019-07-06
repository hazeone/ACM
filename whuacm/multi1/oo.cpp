#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
const int N=1e4+100;
const int M=26;
#define LL long long
int mod=1e9+7;
string s[N];
int n,m;
int sum[maxn],bas[maxn];
struct sam{
	int cnt,last;
	int link[maxn*2],trans[maxn*2][M],mx[maxn*2],ans[maxn*2],vis[maxn*2],built[maxn*2];
	sam()
	{
		last=cnt=1;
	}
	int add(int c,int begin)
	{
		int p=begin,np=++cnt;
		mx[np]=mx[p]+1;//
		ans[np]=1;
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
				ans[nq]=1;
				memcpy(trans[nq],trans[q],sizeof(trans[q]));
				link[nq]=link[q];
				link[np]=link[q]=nq;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
			}
		}
		return np;
	}
	void build(string t,int x,int flag)
	{
		int len=t.length(),now=1;
		for(int i=0;i<len;i++)
		{
			now=trans[now][t[i]-'a'];
			int tmp=now;
			while(tmp!=1&&vis[tmp]!=flag)
			{
				ans[tmp]=1LL*x*ans[tmp]%mod;
				vis[tmp]=flag;
				tmp=link[tmp];
			}
		}
	}
	void build(int now){
		built[now]=1;
		sum[mx[link[now]]+1] = (sum[mx[link[now]]+1]+ans[now])%mod;
		sum[mx[now]+1] = (sum[mx[now]+1]-ans[now]+mod)%mod;
		for (int i=0;i<26;i++){
			if(!trans[now][i]||built[trans[now][i]])continue;
			build(trans[now][i]);
		}
	}
}SAM;
int qpow(int a,int b)
{
	int re=1;
	while(b)
	{
		if(b&1)re=1LL*re*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	scanf("%d",&n);
	int now;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int len=s[i].length();
		now=1;
		for(int j=0;j<len;j++)
		{
			now=SAM.add(s[i][j]-'a',now);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		SAM.build(s[i],x,i);
	}
	//SAM.slove();
	SAM.ans[1]=0;
    SAM.build(1);
    for (int i=1;i<maxn;i++){
      sum[i]=(sum[i-1]+sum[i])%mod;
    }
    for (int i=1;i<maxn;i++){
      sum[i]=(sum[i]+sum[i-1])%mod;
    }
	bas[0]=1;
    for (int i=1;i<maxn;i++)
    {
		bas[i]=26LL*bas[i-1]%mod;
    }
    for(int i=2;i<maxn;i++)
    {
		bas[i]=(bas[i]+bas[i-1])%mod;
    }
    for (int i=1;i<maxn;i++)
    {
		sum[i]=1LL*sum[i]*qpow(bas[i],mod-2)%mod;
    }
    cin>>m;
    while(m--)
    {
		int x;
		cin>>x;
		cout<<sum[x]<<'\n';
	}
	return 0;
}
