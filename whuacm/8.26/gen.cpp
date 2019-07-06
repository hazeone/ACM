#include<cstdio>
#include<ctime>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<climits>
#include<cstring> 
#include<algorithm>
typedef long long ll;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define fd(x,y,z) for(int x=y;x>=z;x--)
int n,m,t,x,y,T;
int main()
{
	freopen("C.in","w",stdout);
	srand(time(0));
	T=2;
	printf("%d\n",T);
	while(T--)
	{
		n=100000;
		m=n+50;
		t=rand()%50+40000;
		printf("%d %d %d\n",n,m,t);
		f(i,1,n-1)
		{
			printf("%d %d %d\n",i+1,rand()%i+1,rand()%5+1);
		}
		f(r,1,m-n+1)
		{
			printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%5+1);
		}
		f(i,1,t)
		{
			printf("%d %d\n",rand()%n+1,rand()%n+1);
		}
	}
	return 0;
}
