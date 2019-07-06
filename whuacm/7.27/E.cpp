#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m;
int a[20],b[50];
int use[20][50],r[50][50],need[20],v[50],v1[50];
long long ans;
void dfs(int pos)
{
	if(pos==n)
	{
		long long maxp=0;
		memset(v1,0,sizeof(v1));
		for(int i=0;i<n;i++)
		{
			if(v[i])
			{
				maxp+=a[i];
				for(int j=0;j<need[i];j++)
				v1[use[i][j]]=1;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(v1[i])maxp-=b[i];
		}
		if(maxp>ans)ans=maxp;
		return;
	}
	v[pos]=0;
	dfs(pos+1);
	v[pos]=1;
	dfs(pos+1);
}
void clr()
{
	ans=0;
}
int main()
{
	freopen("E.in","r",stdin);
	cin>>T;
	for(int q=1;q<=T;q++)
	{
		clr();
		cin>>n>>m;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<m;i++)
		cin>>b[i];
		for(int i=0;i<n;i++)
		{
			cin>>need[i];
			for(int j=0;j<need[i];j++)
			cin>>use[i][j];
		}
		for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		cin>>r[i][j];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<need[i];j++)
			{
				int x=use[i][j];
				for(int k=0;k<m;k++)
				{
					if(r[x][k]==1)
					{
						int flag=0;
						for(int p=0;p<need[i];p++)
						{
							if(use[i][p]==k)
							flag=1;
						}
						if(!flag)
						{
							need[i]++;
							use[i][need[i]-1]=k;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<need[i];j++)
			cout<<use[i][j]<<" ";
			cout<<endl;
		}
		dfs(0);
		cout<<"Case #"<<q<<": "<<ans<<endl;
	}
	return 0;
}
