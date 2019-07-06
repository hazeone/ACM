#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct point 
{
	double x,y;
}a[300],b[300],s[300],t[300];
int n,m,tot1,tot2,T,sum;
bool cmp(point A,point B)
{
	if(A.x!=B.x)
	return A.x<B.x;
	return A.y<B.y;
}
point operator -(point A,point B)
{
    point c;
    c.x=A.x-B.x;
    c.y=A.y-B.y;
    return c;
}
double operator /(point A,point B)
{
	if(B.x!=0&&A.x!=0)return A.x/B.x;
	else return A.y/B.y;
}
bool operator ==(point A,point B)
{
	if(A.x==B.x&&A.y==B.y)return true;
	return false;
}
double cross(point A,point B)
{
    return A.x*B.y-B.x*A.y;
}
void dopack1()
{
	tot1=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		while(tot1>1&&cross(s[tot1-1]-s[tot1-2],a[i]-s[tot1-2])<=0)tot1--;
		s[tot1++]=a[i];
	}
	int k=tot1;
	for(int i=n-1;i>0;i--)
	{
		while(tot1>k&&cross(s[tot1-1]-s[tot1-2],a[i]-s[tot1-2])<=0)tot1--;
		s[tot1++]=a[i];
	}
	if(n>1)tot1--;
}
void dopack2()
{
	tot2=0;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		while(tot2>1&&cross(t[tot2-1]-t[tot2-2],b[i]-t[tot2-2])<=0)tot2--;
		t[tot2++]=b[i];
	}
	int k=tot2;
	for(int i=m-1;i>0;i--)
	{
		while(tot2>k&&cross(t[tot2-1]-t[tot2-2],b[i]-t[tot2-2])<=0)tot2--;
		t[tot2++]=b[i];
	}
	if(m>1)tot2--;
}
bool check5(point A,point B,point C,point D)
{
	double a1=(C-A)/(B-A);
	double a2=(D-A)/(B-A);
	if(a1<0&&a2<0)return false;
	if(a1>1&&a2>1)return false;
	if((a1<1&&a1>=0)||(a2<1&&a2>=0))return true;
	if(a1==1||a2==1)return true;
	if((a1>1&&a2<0)||(a2>1&&a1<0))return true;
	return false;	
}
bool check2(point A,point B,point C,point D)
{
	if(cross(A-B,C-D)==0)
	{
		return check5(A,B,C,D);
	}
	int f1,f2;
	double t1=cross(B-A,C-A),t2=cross(B-A,D-A),t3=cross(D-C,B-C),t4=cross(D-C,A-C);
	if(t1==0||t2==0)f1=0;
	else if((t1<0&&t2<0)||(t1>0&&t2>0))f1=1;
	else f1=2;
	if(t3==0||t4==0)f2=0;
	else if((t3<0&&t4<0)||(t3>0&&t4>0))f2=1;
	else f2=2;
	if(f1==0&&f2==0)return true;
	if(f1==0&&f2==1)return false;
	if(f1==0&&f2==2)return true;
	if(f1==1&&f2==0)return false;
	if(f1==1&&f2==1)return false;
	if(f1==1&&f2==2)return false;
	if(f1==2&&f2==0)return true;
	if(f1==2&&f2==1)return false;
	if(f1==2&&f2==2)return true;
	return false;
}
bool check3()
{
	point A=s[0];
    int l=1,r=tot2-2,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        double a1=cross(t[mid]-t[0],A-t[0]);
        double a2=cross(t[mid+1]-t[0],A-t[0]);
        if(a1>=0&&a2<=0)
        {
            if(cross(t[mid+1]-t[mid],A-t[mid])>=0)return true;
            return false;
        }
        else if(a1<0)
        {
            r=mid-1;
        }
        else 
        {
            l=mid+1;
        }
    }
    return false;
}
bool check4()
{
	point A=t[0];
    int l=1,r=tot1-2,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        double a1=cross(s[mid]-s[0],A-s[0]);
        double a2=cross(s[mid+1]-s[0],A-s[0]);
        if(a1>=0&&a2<=0)
        {
            if(cross(s[mid+1]-s[mid],A-s[mid])>=0)return true;
            return false;
        }
        else if(a1<0)
        {
            r=mid-1;
        }
        else 
        {
            l=mid+1;
        }
    }
    return false;
}
bool check()
{
	if(tot1==0||tot2==0)return true;
	if(tot1==1)
	{
		if(tot2>2&&check3())return false;
		if(tot2==2&&(cross(t[0]-s[0],t[1]-s[0])==0&&(t[0]==s[0]||t[1]==s[0]||((t[0]-s[0])/(t[1]-s[0])<0))))return false;
		return true;
	}
	if(tot2==1)
	{
		if(tot1>2&&check4())return false;
		if(tot1==2&&(cross(s[0]-t[0],s[1]-t[0])==0&&(s[0]==t[0]||s[1]==t[0]||((s[0]-t[0])/(s[1]-t[0])<0))))return false;
		return true;
	}
	for(int i=0;i<tot1;i++)
	for(int j=0;j<tot2;j++)
	{
		if(check2(s[i],s[i+1],t[j],t[j+1]))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("1.in","r",stdin);
	cin>>T;
	while(T--)
	{
		n=m=0;
		cin>>sum;
		for(int i=1;i<=sum;i++)
		{
			double xx,yy;
			int c;
			scanf("%lf%lf%d",&xx,&yy,&c);
			if(c==0)
			{
				a[++n].x=xx;
				a[n].y=yy;
			}
			if(c==1)
			{
				b[++m].x=xx;
				b[m].y=yy;
			}
		}
		dopack1();
		dopack2();
		if(check())
		printf("1\n");
		else printf("0\n");
	}
}
