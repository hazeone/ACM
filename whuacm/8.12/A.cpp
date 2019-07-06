#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double x,y,ans=-1;
int main()
{
	freopen("1.in","r",stdin);
	cin>>x>>y;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double q, w,e;
		cin>>q>>w>>e;
		if(ans<0)ans=sqrt((q-x)*(q-x)+(w-y)*(w-y))/e;
		else ans=min(ans,sqrt((q-x)*(q-x)+(w-y)*(w-y))/e);
	}
	cout<<ans<<endl;
	printf("%.6f\n",ans);
	return 0;
}
