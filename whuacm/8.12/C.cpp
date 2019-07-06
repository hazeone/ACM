#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long c[200000],f[100005][2];
int n;
string a[200000],b[2000000];
int main()
{
	freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		reverse(b[i].begin(),b[i].end());
	}
	memset(f,-1,sizeof(f));
	f[1][1]=c[1];
	f[1][0]=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1]&&f[i-1][0]!=-1)
		f[i][0]=f[i-1][0];
		if(a[i]>=b[i-1]&&f[i-1][1]!=-1)
		{
			if(f[i][0]!=-1)
			f[i][0]=min(f[i][0],f[i-1][1]);
			else
			f[i][0]=f[i-1][1];
		}
		if(b[i]>=a[i-1]&&f[i-1][0]!=-1)
		f[i][1]=f[i-1][0]+c[i];
		if(b[i]>=b[i-1]&&f[i-1][1]!=-1)
		{
			if(f[i][1]!=-1)
			{
				f[i][1]=min(f[i-1][1],f[i][1]-c[i])+c[i];
			}
			else
			f[i][1]=f[i-1][1]+c[i];
		}
		if(f[i][0]==-1&&f[i][1]==-1)break;
	}
	if(f[n][0]==-1&&f[n][1]==-1)
	cout<<-1<<endl;
	else if(f[n][0]!=-1&&f[n][1]!=-1)cout<<min(f[n][0],f[n][1])<<endl;
	else if(f[n][0]==-1)cout<<f[n][1]<<endl;
	else cout<<f[n][0]<<endl;
	return 0;
}

