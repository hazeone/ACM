#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,ans=0;
char s[5002];
short f[12500010];
bool judge(char x,char y)
{
	if(x==')'||y=='(')return false;
	return true;
}
inline int gt(int x,int y)
{
	return (n+n-x+1)*(x)/2+y;
}
void dfs(int l,int r)
{
	if((r-l+1)%2==1)
	{
		dfs(l,r-1);
		dfs(l+1,r);
		return;
	}
	if(f[gt(l,r)]!=0||l>=r)return;
	if(r-l==1)
	{
		if(judge(s[l],s[r]))
		{
			ans++;
			f[gt(l,r)]=1;
		}
		else
		{
			f[gt(l,r)]=-1;
		}
		return;
	}
	if(judge(s[l],s[r]))
	{
		dfs(l+1,r-1);
		if(f[gt(l+1,r-1)]==1)
		{
			f[gt(l,r)]=1;
		}
	}
	for(int i=l+1;i<=r;i+=2)
	{
		dfs(l,i);
		dfs(i+1,r);
		if(f[gt(l,i)]==1&&f[gt(i+1,r)]==1)
		{
			f[gt(l,r)]=1;
		}
	}
	ans+=f[gt(l,r)];
	if(f[gt(l,r)]==0)f[gt(l,r)]=-1;
	return;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	dfs(0,n-1);
	cout<<ans<<endl;
	/*n=5;
	for(int i=0;i<5;i++)
	{
		for(int j=i;j<5;j++)
	cout<<gt(i,j);
	cout<<endl;
}*/
	return 0;
}
