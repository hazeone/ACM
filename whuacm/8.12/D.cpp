#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int ch[3200000][2];
int n,x,tot=1,ans,sum[3200000];
char s;
void add(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!ch[now][1])ch[now][1]=++tot;
			now=ch[now][1];
			//cout<<x<<" "<<1<<" "<<now<<" "<<sum[now]<<endl;
			sum[now]++;
		}
		else
		{
			if(!ch[now][0])ch[now][0]=++tot;
			now=ch[now][0];
			//cout<<x<<" "<<0<<" "<<now<<" "<<sum[now]<<endl;
			sum[now]++;
		}
	}
}
void del(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!ch[now][1])ch[now][1]=++tot;
			now=ch[now][1];sum[now]--;
		}
		else
		{
			if(!ch[now][0])ch[now][0]=++tot;
			now=ch[now][0];sum[now]--;
		}
	}
}
void query(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(sum[ch[now][0]])
			{
				ans+=(1<<i);
			    now=ch[now][0];
			}
			else now=ch[now][1];
		}
		else
		{
			if(sum[ch[now][1]])
			{
				ans+=(1<<i);
				now=ch[now][1];
			}
			else now=ch[now][0];
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	cin>>n;
	add(0);
	while(n--)
	{
		cin>>s>>x;
		if(s=='+')
		{
			add(x);
		}
		if(s=='-')
		{
			del(x);
		}
		if(s=='?')
		{
			ans=0;
			query(x);
			printf("%d\n",ans);
		}
	}
	return 0;
}
