#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N=100005;
#define eps 1e-6
int m,n;
char s[N];
int  a[N],b[N],ok;
int mx=1e9+7;
int cnt=1;
int check(int x)
{
	int y;
	int re=0;
	printf("%d\n",x);
	fflush(stdout);
	scanf("%d",&y);
	if(y==0)exit(0);
	if(a[cnt]==-1)
	re=y;
	else re=-y;

	cnt=cnt%n+1;
	return re;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",m);
		fflush(stdout);
		scanf("%d",a+i);
		if(a[i]==0)exit(0);
	}
	int l=1,r=m,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		int t=check(mid);
		if(t==-1)
		{
			r=mid;
		}
		if(t==1)
		{
			l=mid+1;
		}
		if(t==0)
		break;
	}
	check(l);
	return 0;
}
