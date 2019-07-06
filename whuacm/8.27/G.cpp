#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int n,m,k;
set<int>s;正在
int f[200000],g[200000];
int sum[200000],tot,sedge;
struct point 
{
	int to,next;
}e[10000000];
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		sum[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==0)
		s.insert(i);
	}//cout<<"!!!!!!"<<endl;
	int sk=k;
	for(int p=1;p<=n;p++)
	{
		int flag=1;
		set<int>::iterator itlast=s.end();itlast--;//cout<<"!!!!!!"<<endl;
		set<int>::iterator itar;
		//cout<<*itlast<<endl;
		for(set<int>::iterator it=s.begin();it!=itlast;it++)
		{//cout<<"!!!!!!"<<endl;
			//cout<<*it<<endl;
			if(f[*it])
			{
				set<int>::iterator tmp=it;
				tmp++;
				f[*it]=*tmp;
				add(*tmp,*it);
				sum[*it]++;
				continue;
			}
			if(f[*it]==0&&sk>0)
			{
				set<int>::iterator tmp=it;
				tmp++;
				f[*it]=*tmp;
				//cout<<*tmp<<" "<<*it<<endl;
				add(*tmp,*it);
				sum[*it]++;//cout<<"!!!!!!"<<endl;
				sk--;
				continue;
			}
			printf("%d ",*it);
			itar=it;
			flag=0;
			break;
		}
		if(flag)
		{
			set<int>::iterator itlast=s.end();itlast--;
			printf("%d ",*itlast);
			int x=*itlast;
			s.erase(s.begin(),s.find(x));
			s.erase(x);
			for(int temp=g[x];temp;temp=e[temp].next)
			{
				sum[e[temp].to]--;
				if(sum[e[temp].to]==0)
				s.insert(e[temp].to);
			}
		}
		else
		{
			int x=*itar;
			s.erase(s.begin(),s.find(x));
			s.erase(x);
			for(int temp=g[x];temp;temp=e[temp].next)
			{
				sum[e[temp].to]--;
				if(sum[e[temp].to]==0)
				s.insert(e[temp].to);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i])ans++;
	}
	cout<<endl<<ans<<endl;
	for(int i=1;i<=n;i++)
	if(f[i])printf("%d %d\n",f[i],i);
	return 0;
}
