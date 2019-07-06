#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[200],b[200],tot,tot1;
int main()
{
	cin>>n>>m;
	if((n*9<m)||(n>1&&m==0))
	{
		cout<<-1<<" "<<-1<<endl;
		return 0;
	}
	a[1]=m?1:0;
	tot=m-1;
	int t=n;
	while(tot>0)
	{
		if(9-a[t]<=tot)
		{
			tot=tot-9-a[t];
			a[t]=9;
			t--;
		}
		else
		{
			a[t]+=tot;
			break;
		}
	}
	t=1;
	tot1=m;
	while(tot1>0)
	{
		if(9<=tot1)
		{
			b[t]=9;
			tot1-=9;
			t++;
		}
		else
		{
			b[t]=tot1;
			break;
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i];cout<<" ";
	for(int i=1;i<=n;i++)cout<<b[i];cout<<endl;
	return 0;
}
