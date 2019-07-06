#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double pi=acos(-1);
double r,v;
int main()
{
	int T;
	cin>>T;
	printf("%.8lf\n",tan(80.0/180.0*pi));
	for(int i=1;i<=T;i++)
	{
		cin>>r>>v;
		printf("Case %d: %.8lf",i,r/2.0*pi/v);
	}
	return 0;
}
