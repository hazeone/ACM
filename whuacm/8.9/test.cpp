#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
struct point
{
	int a,p;
}c[1005];
int T,n,sum,ans=0,r[1002][1002];
bool cmp(point x,point y)
{
	return x.a<y.a;
}
int main()
{
	freopen("1005.in","r",stdin);
	scanf("%d",&T);
	for(int q=1;q<=T;q++)
	{
		ans=0;
		printf("Case #%d: ",q);
		memset(r,0,sizeof(r));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i].a);
			c[i].p=i;
		}
		sort(c+1,c+1+n,cmp);
		int fff=0;
		for(int i=1;i<=n;i++)
		{
			sum=c[i].a;
			for(int j=1;j<i;j++)
			{
				if(sum==0)break;
				if(c[j].a<c[i].a)
				{
					sum--;
					r[c[i].p][c[j].p]=1;
					ans++;
				}
			}
			if(sum>0)
			{
				fff=1;
				break;
			}
		}
		if(fff)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			cout<<ans<<endl;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(r[i][j])
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}
