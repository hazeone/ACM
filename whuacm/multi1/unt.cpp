#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
double eps=1e-8;
double mx=asin(1.0);
double a[5];
double h[5],A[5];
double x[5],y[5],w;
double sqt;
double pw(double X)
{
	return X*X;
}
double dis(int i,int j)
{
	return sqrt(pw(x[i]-x[j])+pw(y[i]-y[j]));
}
double cha(double X,double Y,double XX,double YY)
{
	return X*YY-XX*Y;
}
double getA(int i,int j,int k)
{
	return acos((pw(a[j])+pw(a[k])-pw(a[i]))/(2.0*a[j]*a[k]));
}
bool equl(double X,double Y)
{
	return abs(X-Y)<eps;
}
int main()
{
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			for(int i=0;i<3;i++)
			{
				scanf("%lf%lf",x+i,y+i);
			}
			scanf("%lf",&w);
			for(int i=0;i<3;i++)
			for(int j=i+1;j<3;j++)
			{
				a[(i+j)%3]=dis(i,j);
			}
			sqt=abs(cha(x[1]-x[0],y[1]-y[0],x[2]-x[0],y[2]-y[0]));
			for(int i=0;i<3;i++)
			{
				h[i]=sqt/a[i];
				A[i]=getA(i,(i+1)%3,(i+2)%3);
			}
			double ans=100001.0;
			for(int i=0;i<3;i++)
			{
				int j=(i+1)%3,k=(i+2)%3;
				if(a[i]<w+eps)
				{
					if(A[j]<mx+eps&&A[k]<mx+eps)
					{
						ans=min(h[i],ans);
					}
					else if(A[j]<mx+eps)
					{
						double tmp=a[k]*cos(A[j]);
						if(tmp<w+eps)
						{
							ans=min(ans,a[k]*sin(A[j]));
						}
					}
					else
					{
						swap(j,k);
						double tmp=a[k]*cos(A[j]);
						if(tmp<w+eps)
						{
							ans=min(ans,a[k]*sin(A[j]));
						}
					}
				}
				if(h[i]<w+eps)
				{
					ans=min(max(a[i],max(a[j],a[k])),ans);
				}
			}
			if(equl(ans,100001.0)){puts("impossible");continue;}
			for(int i=0;i<3;i++)
			{
				int j=(i+1)%3,k=(i+2)%3;
				if((equl(A[j],mx)||equl(A[k],mx))&&equl(a[i],w))continue;
				if(a[i]+eps>w)
				{
					double tmp=acos(w/a[i]);
					if(A[j]+tmp<mx+eps)
					{
						if(cos(A[j]+tmp)*a[k]<w+eps)
						ans=min(ans,max(sin(A[j]+tmp)*a[k],sqrt(pw(a[i])-pw(w))));
					}
					if(A[j]<tmp+eps&&A[k]<mx-tmp+eps)
					{
						ans=min(ans,sqrt(pw(a[i])-pw(w)));
					}
					swap(j,k);
					if(A[j]+tmp<mx+eps)
					{
						if(cos(A[j]+tmp)*a[k]<w+eps)
						ans=min(ans,max(sin(A[j]+tmp)*a[k],sqrt(pw(a[i])-pw(w))));
					}
					if(A[j]<tmp+eps&&A[k]<mx-tmp+eps)
					{
						ans=min(ans,sqrt(pw(a[i])-pw(w)));
					}
				}
			}
			printf("%.9f\n",ans);
		}
	}
	return 0;
}
