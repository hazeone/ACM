#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
const double eps = 1e-6;
const double pi=acos(-1);
struct point 
{
	double x,y;
}a[10];
point operator -(point A,point B)
{
	point C;
	C.x=A.x-B.x;
	C.y=A.y-B.y;
	return C;
}
double dot(point A,point B)
{
	return A.x*B.x+A.y*B.y;
}
double length(point A)
{
	return sqrt(dot(A,A));
}
double workcross(point A,point B)
{
	//cout<<dot(A,B)/length(A)/length(B)<<endl;
	return acos(dot(A,B)/length(A)/length(B));
}
point inter(point A,point B,double k,double b)
{
	double l=0,r=B.x;
	point re;
	while(l+eps<r)
	{
		 re.x=(l+r)/2.0;
		 re.y=k*re.x+b;
		 double tar=25.0/180.0*pi;
		 if(workcross(A-re,B-re)<tar)
		 {
			 l=re.x;
		 }
		 else
		 {
			 r=re.x;
		 }
	}
	re.x=(l+r)/2.0;
	re.y=k*re.x+b;
	return re;
}
double workline()
{
	double l = -5.67128182, r = 5.67128182;
	double k,b;
	point p1,p2;
	while(r-l>eps)
	{
		k = (l + r) / 2.0;
		b=a[2].y-k*a[2].x;
		p1=inter(a[1],a[2],k,b);
		p2=inter(a[3],a[2],k,b);
		if(p1.x>p2.x)r=k;
		else l=k;
	}
	k = (l + r) / 2.0;
	cout<<k<<endl;
	b=a[2].y-k*a[2].x;
	p1=inter(a[1],a[2],k,b);
	double ans=2.0*p1.y/p1.x-k;
	return atan(ans);
}
int main()
{
	freopen("K.in","r",stdin);
	cin>>T;
	for(int p=1;p<=T;p++)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y);
		printf("Case %d: %.8lf\n",p,workline()/pi*180.0);
	}
	return 0;
}
