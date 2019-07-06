#include<bits/stdc++.h>
using namespace std;

int a[20],w[20];
int n,m,ok,ans;
void dfs(int x)
{
	if(x==0)
	{
		ok=1;
		return;
	}
	for(int i=1;i<=ans;i++)
	{
		if(a[i]+w[x]<=m)
		{
			a[i]+=w[x];
			dfs(x-1);
			a[i]-=w[x];
			if(ok)return;
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",w+i);
			sum+=w[i];
		}
		ans=sum/m,ok=0;
		sort(w+1,w+1+n);//需要从大往小搜索，这样快很多
		while(1)
		{
			for(int i=1;i<=ans;i++)
			a[i]=0;
			dfs(n);
			if(ok)break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
