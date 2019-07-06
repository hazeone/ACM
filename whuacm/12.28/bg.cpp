/*
 * 求最小的稳定婚姻匹配
 * 每次找单身男性去和他没有表白过的且最喜欢的女性表白
 * 如果女性也更喜欢他就和他结成一对
 */
#include<bits/stdc++.h>
using namespace std;
const int N=205;
int man[N][N],woman[N][N],match[N],v[N][N],patch[N],rev[N][N];
int n;
queue<int>q[N];
int check(int x)
{
	memset(v,0,sizeof(v));
	memset(match,0,sizeof(match));
	memset(patch,0,sizeof(patch));
	while(1)
	{
		int ok=0;
		for(int i=1;i<=n;i++)
		{
			if(!match[i])
			{
				for(int j=1;j<=x;j++)
				{
					if(!v[i][j])
					{
						v[i][j]=1;
						q[man[i][j]].push(i);
						break;
					}
				}
			}
		}
		int mx,p;
		for(int i=1;i<=n;i++)
		{
			if(patch[i])
			{
				mx=rev[i][patch[i]];
				p=patch[i];
			}
			else
			{
				mx=p=n+1;
			}
			while(!q[i].empty())
			{
				ok=1;
				int tmp=q[i].front();
				if(rev[i][tmp]<mx)
				{
					mx=rev[i][tmp];
					p=tmp;
				}
				q[i].pop();
			}
			if(mx>x)continue;
			if(patch[i])match[patch[i]]=0;
			if(p!=n+1)
			{
				patch[i]=p;
				match[p]=i;
			}
		}
		if(!ok)break;
	}
	for(int i=1;i<=n;i++)
	{
		if(match[i]==0)return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		scanf("%d",&man[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&woman[i][j]);
			rev[i][woman[i][j]]=j;
		}
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	check(l);
	printf("%d\n",l);
	for(int i=1;i<=n;i++)
	{
		if(i==1)printf("%d",match[i]);
		else printf(" %d",match[i]);
	}
	return 0;
}
