#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
int t=10;
int lg,lm;
int mod=10000;
struct point
{
	int x,y;
}a[4];
bool operator ==(point X,point Y)
{
	return ((X.x==Y.x)&&(X.y&&Y.y));
}
int main()
{
	srand(time(0));
	cout<<t<<endl;
	while(t--)
	{
		lg=rand()%mod+1;
		lm=rand()%mod+1;
		a[1].x=rand()%mod;
		a[1].y=rand()%mod;
		a[2].x=rand()%mod;
		a[2].y=rand()%mod;
		while(a[2]==a[1])
		{
			a[2].x=rand()%mod;
		a[2].y=rand()%mod;
		}
		a[3].x=rand()%mod;
		a[3].y=rand()%mod;
		while(a[2]==a[1]&&a[3]==a[1])
		{
			a[3].x=rand()%mod;
		   a[3].y=rand()%mod;
		}
		for(int i=1;i<=3;i++)
		printf("%d %d\n",a[i].x,a[i].y);
	}
	return 0;
}

