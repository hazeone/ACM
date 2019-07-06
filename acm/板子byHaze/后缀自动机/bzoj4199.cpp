/*
两个长度为r的子串相同称为r相似。两个r相似的子串的价值是两个子串开头位置的价值乘积。
求r相似的子串数量和最大的代价(r=0…n-1)
品酒大会
后缀自动机+dp
*/
#include<bits/stdc++.h>
using namespace std;
const int N=600020;
const int M=26;
#define LL long long
char s[N];
int n;
int g[N*2],tot=0;
struct point
{
	int to,next;
}e[N*2];
struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2];
	LL ans1[N],ans2[N],mm[N*2],nn[N*2],w[N*2],mnode[N*2],size[N*2],b[N];
	sam(){last=cnt=1;}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		mnode[last]=1;
		mx[np]=mx[p]+1;
		size[np]=1;//
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];
		if(!p){
			link[np]=1;
		}
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
	void addedge(int x,int y){e[++tot].to=y;e[tot].next=g[x];g[x]=tot;}
	void dfs(int x)
	{
		if(mnode[x]){
			mm[x]=nn[x]=w[x];
		}
		else mm[x]=-1e9-1,nn[x]=1e9+1;
		for(int tmp=g[x];tmp;tmp=e[tmp].next)
		{
			int y=e[tmp].to;
			dfs(y);

			if(mm[x]!=-1e9-1&&mm[y]!=-1e9-1&&nn[x]!=1e9+1&&nn[y]!=1e9+1)
			ans2[mx[x]]=max(max(ans2[mx[x]],mm[x]*mm[y]),nn[x]*nn[y]);
			ans1[mx[x]]+=size[x]*size[y];
			mm[x]=max(mm[x],mm[y]);
			nn[x]=min(nn[x],nn[y]);
			size[x]+=size[y];
		}
	}
	void slove()
	{
		int p=1;
		for(int i=n-1;i>=0;i--)
		{
			int c=s[i]-'a';
			p=trans[p][c];
			w[p]=b[i+1];
		}
		for(int i=2;i<=cnt;i++)
		addedge(link[i],i);
		for(int i=0;i<=n;i++)ans2[i]=-1e18;
		dfs(1);
		for(int i=n-1;i>=0;i--)
		{
			ans1[i]+=ans1[i+1];
			ans2[i]=max(ans2[i],ans2[i+1]);
		}
		for(int i=0;i<n;i++)
		if(ans1[i])printf("%lld %lld\n",ans1[i],ans2[i]);
		else puts("0 0");
	}
}SAM;
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++)SAM.add(s[n-i-1]-'a');
	for(int i=1;i<=n;i++)scanf("%lld",&SAM.b[i]);
	SAM.slove();
	return 0;
}
/*
12
abaabaabaaba
1 -2 3 -4 5 -6 7 -8 9 -10 11 -12
*
10
ponoiiipoi
2 1 4 7 4 8 3 6 4 7
*/
