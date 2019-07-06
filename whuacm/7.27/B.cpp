#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	int x,y;
}task[200000],mach[200000];
int m,n,num[101],j;
bool cmp(point a,point b)
{
	if(a.x==b.x)
	{
		return a.y>b.y;
	}
	return a.x>b.x;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&mach[i].x,&mach[i].y);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&task[i].x,&task[i].y);
		}
		sort(mach+1,mach+1+n,cmp);
		sort(task+1,task+1+m,cmp);
		long long ans=0;
		memset(num,0,sizeof(num));
		j=1;int ooo=0;
		for(int i=1;i<=m;i++)
		{
			while(j<=n&&mach[j].x>=task[i].x)
			{
				num[mach[j].y]++;
				j++;
			}
			for(int k=task[i].y;k<=100;k++)
			{
				if(num[k])
				{
					num[k]--;
					ans+=task[i].y*2+task[i].x*500;
					ooo++;
					break;
				}
			}
		}
		cout<<ooo<<" "<<ans<<endl;
	}
	return 0;
}
