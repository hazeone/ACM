/*
 * 维护双端加字母的回文自动机
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=800005;
const int N=27;
#define LL long long
struct Palindromic_Tree
{
	int trans[MAXN][N];//trans指针，trans指针和字典树类似，指向的串为当前串两端加上同一个字符构成
	int fail[MAXN];//fail指针，失配后跳转到fail指针指向的节点
	int cnt[MAXN];//cnt[i]表示节点i表示的本质不同的串的个数
	int num[MAXN];//num[i]表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数。
	int len[MAXN];//len[i]表示节点i表示的回文串的长度
	int S[MAXN];//存放添加的字符
	int last[2];//指向上一个字符所在的节点，方便下一次add
	int n,L,R;
	LL tot;//字符数组指针
	int p;//节点指针
	int newnode(int l)//新建节点
	{
		for(int i=0;i<N;++i)trans[p][i]=0;
		cnt[p]=0;
		num[p]=0;
		len[p]=l;
		return p++;
	}
	void init(int x)//初始化
	{
		memset(S,-1,sizeof(S));
		tot=p=0;
		newnode(0);
		newnode(-1);
		last[1]=last[0]=0;
		L=x;
		R=x-1;
		//n=0;
		//S[n]=-1;//开头放一个字符集中没有的字符，减少特判
		tot=0;
		fail[0]=1;
	}
	int get_fail(int x,int op)
	{//和KMP一样，失配后找一个尽量最长的
		if(op)while(S[R-len[x]-1]!=S[R])x=fail[x];
		else while(S[L+len[x]+1]!=S[L])x=fail[x];
		return x;
	}
	void add(int c,int x)
	{
		c=c-'a'+1;
		if(x)
		S[++R]=c;
		else S[--L]=c;
		int cur=get_fail(last[x],x) ;//通过上一个回文串找这个回文串的匹配位置
		if (!trans[cur][c])//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
		{
			int now=newnode(len[cur]+2);//新建节点
			fail[now]=trans[get_fail(fail[cur],x)][c];//和AC自动机一样建立fail指针，以便失配后跳转
			trans[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last[x]=trans[cur][c];
		if(len[last[x]]==R-L+1)last[x^1]=last[x] ;
		cnt[last[x]]++;
		tot+=num[last[x]];
	}
}PT;
char s[MAXN];
int main()
{
	int Q;
	while(~scanf("%d",&Q))
	{
		PT.init(Q);
		while(Q--)
		{
			int x;
			char s[5];
			scanf("%d",&x);
			if(x<=2)
			{
				scanf("%s",s);
				PT.add(s[0],x-1);
			}
			else if(x==3)
			{
				printf("%d\n",PT.p-2);
			}
			else printf("%lld\n",PT.tot);
		}
	}
	return 0;
}
