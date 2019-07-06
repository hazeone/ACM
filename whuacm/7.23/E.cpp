#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
double a,b,m,n;
int T,v;
void dfs(double s)
{
	if(s==360)v=1;
	if(s>360||v)return;
	dfs(s+a);
	dfs(s+b);
}
int main()
{
	cin>>T;
	while(T--)
	{
		v=0;
		cin>>n>>m;
		a=180-360.0/n;
		b=180-360.0/m;
		dfs(0);
		if(v)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
