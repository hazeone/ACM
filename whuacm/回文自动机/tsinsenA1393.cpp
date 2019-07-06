/*
 * 统计取两相交回文子串的个数
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=2000005;
const int N=26;
#define LL long long
LL sum[MAXN];
LL mod=51123987;
struct Palindromic_Tree
{
	int trans[MAXN][N];//trans指针，trans指针和字典树类似，指向的串为当前串两端加上同一个字符构成
	int fail[MAXN];//fail指针，失配后跳转到fail指针指向的节点
	int num[MAXN];//num[i]表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数。
	int len[MAXN];//len[i]表示节点i表示的回文串的长度
	int S[MAXN];//存放添加的字符
	int last;//指向上一个字符所在的节点，方便下一次add
	int n;//字符数组指针
	int p;//节点指针
	int newnode(int l)//新建节点
	{
		for(int i=0;i<N;++i)trans[p][i]=0;
		num[p]=0;
		len[p]=l;
		return p++;
	}
	void init()//初始化
	{
		p=0;
		newnode(0);
		newnode(-1);
		last=0;
		n=0;
		S[n]=-1;//开头放一个字符集中没有的字符，减少特判
		fail[0]=1;
	}
	int get_fail(int x)
	{//和KMP一样，失配后找一个尽量最长的
		while(S[n-len[x]-1]!=S[n])x=fail[x];
		return x;
	}
	LL add(int c)
	{
		c=c-'a';
		S[++n]=c;
		int cur=get_fail(last) ;//通过上一个回文串找这个回文串的匹配位置
		if (!trans[cur][c])//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
		{
			int now=newnode(len[cur]+2);//新建节点
			fail[now]=trans[get_fail(fail[cur])][c];//和AC自动机一样建立fail指针，以便失配后跳转
			trans[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=trans[cur][c];
		return num[last];
	}
}PT;
char s[MAXN];
int main()
{
	int n;
	cin>>n;
	scanf("%s",s);
	PT.init();
	for(int i=n-1;i>=0;i--)
	{
		sum[i]=(sum[i+1]+PT.add(s[i]))%mod;
	}
	PT.init();
	LL ans=0,tot=0,tmp;
	for(int i=0;i<n;i++)
	{
		tmp=PT.add(s[i]);
		ans=(ans+tmp*sum[i+1])%mod;
		tot=(tot+tmp)%mod;
	}
	tot=tot*(tot-1)%mod*25561994LL%mod;
	cout<<(tot-ans+mod)%mod<<endl;
	return 0;
}



