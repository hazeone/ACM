#include<bits/stdc++.h>
using namespace std;
const int M = 1000010;
int flag1;
int flag[M],pl[M],a[M],vis[M],hh,k,n;
void print()
{
	if(flag1)
		return ;
	flag1=1;
	int cao=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		int k=pl[i];
		if(!flag[k-1])
			continue;
		while(1)
		{
			cao++;
			printf("%d",a[k]);
			if(cao!=n)
				printf(" ");
			vis[a[k]]=1;
			if(flag[k])
				break;
			k++;
		}
	}
	printf("\n");
}
void dfs(int x);
bool deal(int x)
{
	if(!flag[pl[x]-1])
	{
		if(hh==k)
		{	
			dfs(x);	
			return true;
		}
		hh++;
		flag[pl[x]-1]=1;
		if(hh==k)
		{	
			dfs(x);	
			return true;
		}
	}
	if(!flag[pl[x]])
	{
		if(hh==k)
		{	
			dfs(x);	
			return true;
		}
		hh++;
		flag[pl[x]]=1;
		if(hh==k)
		{	
			dfs(x);	
			return true;
		}
	}
	return false;
}
void dfs(int x)
{
	if(x==n)
	{
		print();
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(pl[i]==pl[i-1]+1)
		{
			if(flag[pl[i-1]])
			{
				flag[pl[i-1]]=0;
				hh--;
			}
			if(!flag[pl[i]])
			{
				if(hh==k)
				{	
					dfs(i);	
					return ;
				}
				hh++;
				flag[pl[i]]=1;
				if(hh==k)
				{	
					dfs(i);	
					return ;
				}
			}
		}
		else
		{
			bool cao=deal(i);
			if(cao)
				return ;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		flag1=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			flag[i]=vis[i]=0;
		hh=flag[0]=flag[n]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pl[a[i]]=i;
		}
		if(k==1)
		{
			for(int i=1;i<n;i++)
				printf("%d ",a[i]);
			printf("%d\n",a[n]);
			continue;
		}
		deal(1);
		if(!flag1)
			dfs(1);
		if(!flag1)
			print();
	}
	return 0;
}
