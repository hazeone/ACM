#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define fd(x,y,z) for(int x=y;x>=z;x--)
int x,y,n,m,ans1,ans2,ans3,k1,k2;
const int en=5005,em=20005;
int head1[en],next1[em],to1[em],sum1[en];
int head2[en],next2[em],to2[em],sum2[en];
void ad1(int x,int y)
{
	k1++;next1[k1]=head1[x];head1[x]=k1;to1[k1]=y;
}
void ad2(int x,int y)
{
	k2++;next2[k2]=head2[x];head2[x]=k2;to2[k2]=y;
}
int dfs1(int x)
{
	printf("x %d\n",x);
	int now=head1[x];
	printf("now %d\n",now);
	sum1[x]=1;
	while(now!=0)
	{
		int y=to1[now];
		printf("y %d sum %d\n",y,sum1[y]);
		if(sum1[y])sum1[x]+=sum1[y];else sum1[x]+=dfs1(y);
		now=next1[now];
	}
	printf("x %d sum %d\n",x,sum1[x]);
	return sum1[x];
}
int dfs2(int x)
{
	int now=head2[x];
	sum2[x]=1;
	while(now!=0)
	{
		int y=to2[now];
		if(sum2[y])sum2[x]+=sum2[y];else sum2[x]+=dfs2(y);
		now=next2[now];
	}
	return sum2[x];
}
int main()
{
	freopen("1.in","r",stdin);
	while(~scanf("%d%d%d%d",&x,&y,&n,&m))
	{
		k1=k2=0;ans1=ans2=ans3=0;
		memset(head1,0,sizeof(head1));
		memset(next1,0,sizeof(next1));
		memset(head2,0,sizeof(head2));
		memset(next2,0,sizeof(next2));
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		f(i,1,m)
		{
			scanf("%d%d",&x,&y);
			x++;y++;
			ad1(x,y);
			ad2(y,x);
		}
		f(i,1,n)if(!sum1[i])dfs1(i);
		f(i,1,n)printf("%d ",sum1[i]);
		printf("\n");
		f(i,1,n)if(!sum2[i])dfs2(i);
		f(i,1,n)if(sum1[i]+x>n)ans1++;
		f(i,1,n)if(sum1[i]+y>n)ans2++;
		f(i,1,n)if(sum2[i]<=y)ans3++;
		printf("%d\n%d\n%d\n",ans1,ans2,ans3);
	}
    return 0;
}
