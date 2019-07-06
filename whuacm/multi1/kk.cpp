#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int L=1e6+10;
#define LL long long
char s[L];
int cnt;
int q[N*60],head,tail;
struct point
{
	int ch[30];
	int fail,val;
}a[N*60];
void clr(int x)
{
	a[x].val=0;
	a[x].fail=0;
	memset(a[x].ch,0,sizeof(a[x].ch));
}
void init(char *c)
{
	int len=strlen(c);
	int x=0;
	for(int i=0;i<len;i++)
	{
		int t=c[i]-'a'+1;
		if(!a[x].ch[t])
		{
			clr(++cnt);
			a[x].ch[t]=cnt;
		}
		x=a[x].ch[t];
	}
	a[x].val++;
}
void buildAC()
{
	head=0,tail=0;
	for(int i=1;i<=26;i++)
	{
		if(a[0].ch[i])
		{
			q[++tail]=a[0].ch[i];
		}
	}
	while(head!=tail)
	{
		int x=q[++head];
		int fail=a[x].fail;
		for(int i=1;i<=26;i++)
		{
			int y=a[x].ch[i];
			if(y)
			{
				a[y].fail=a[fail].ch[i];
				q[++tail]=y;
			}
			else a[x].ch[i]=a[fail].ch[i];
		}
	}
}
int find(char *c)
{
	int len=strlen(c);
	int x=0,ans=0;
	for(int i=0;i<len;i++)
	{
		int t=c[i]-'a'+1;
		while(x&&!a[x].ch[t])x=a[x].fail;
		x=a[x].ch[t];
		int p=x;
		while(p&&a[p].val!=-1)
		{
			ans+=a[p].val;
			a[p].val=-1;
			p=a[p].fail;
		}
	}
	return ans;
}
int main()
{
	int T;
	while(~scanf("%d",&T))
	{
		while(T--)
		{
			int n;
			scanf("%d",&n);
			clr(0);
			for(int i=1;i<=n;i++)
			{
				scanf("%s",s);
				init(s);
			}
			buildAC();
			scanf("%s",s);
			printf("%d\n",find(s));
		}
	}
	return 0;
}
