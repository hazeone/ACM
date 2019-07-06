#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

#define LL long long
const int N=200010;
/*
 * 读入n个x%ai=ri的方程判断是否有解
 * poj2891
 */
int n;
LL a[N],r[N];
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    /*if(b==0) return x=1,y=0,a;
    LL tmp=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return tmp;*/
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL ans = exgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;

    return ans;
}
LL solve()
{
	LL R=r[1],A=a[1],d,x,y;
	for(int i=2;i<=n;i++)
	{
		d=exgcd(A,a[i],x,y);
		if((R-r[i])%d)return -1;
		x=(R-r[i])/d*x%a[i];//记得要模‘a2’,使方程得到最小正数解
		R=R-x*A;
		A=A/d*a[i];
		R%=A;
	}
	d=exgcd(1,A,x,y);
	if(R%d)return -1;
	x=R/d*x;
	return (x%A+A)%A;
	//return (R%A+A)%A;
}
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld",&a[i],&r[i]);
		}
		printf("%lld\n",solve());
	}
	return 0;
}
