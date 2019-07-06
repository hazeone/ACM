#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,top;
struct data{
   double x,y;
}p[200003],s[200003];
double dis(data a,data b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double mul(data p1,data p2,data p0)
{return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);}
inline bool cmp(data a,data b)
{
	if(mul(a,b,p[0])==0)return dis(a,p[0])<dis(b,p[0]);
	return mul(a,b,p[0])>0;
}
int graham()
{
	top=2;data t;
	int k=0;
	for(int i=1;i<n;i++)
	    if((p[k].y>p[i].y)||(p[k].y==p[i].y&&p[k].x>p[i].x))k=i;
	t=p[0];p[0]=p[k];p[k]=t;
	sort(p+1,p+n,cmp);
	s[0]=p[0],s[1]=p[1],s[2]=p[2];
	for(int i=3;i<n;i++)
	{
		while(top&&mul(p[i],s[top],s[top-1])>0)
		   top--;
        s[++top]=p[i];
	}
    s[++top]=p[0];
    //for(int i=0;i<top;i++)
    //cout<<s[i].x<<" "<<s[i].y<<endl;
	return top;
}
bool same(data q,data w,data e)
{
	double x1=q.x-w.x,x2=q.x-e.x,y1=q.y-w.y,y2=q.y-e.y;
	//cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<endl;
	if(abs(x2*y1-x1*y2)<=0.000001)return true;
	else return false;
}
bool check2()
{
	data tmp;
	for(int i=0;i<n;i++)
	{
		int flag=1;
		for(int j=0;j<top;j++)
		if(s[j].x==p[i].x&&s[j].y==p[i].y)
		flag=0;
		if(flag)
		tmp=p[i];
	}
	//cout<<tmp.x<<" "<<tmp.y<<endl; 
	if(same(s[0],s[2],tmp)&&same(s[1],s[3],tmp))
	return true;
	return false;
}
bool check(data begin,data last)
{
	int re=0;
	for(int i=0;i<n;i++)
	{
		if(same(begin,last,p[i]))re++;
	}
	if(re>=n-1)return true;
	else return false;
}
bool judge()
{
	double x1=s[0].x-s[1].x,x2=s[3].x-s[2].x,x3=s[0].x-s[3].x,x4=s[1].x-s[2].x;
	double y1=s[0].y-s[1].y,y2=s[3].y-s[2].y,y3=s[0].y-s[3].y,y4=s[1].y-s[2].y;
	return abs(x1*y2-x2*y1)<=0.0000001&&abs(x3*y4-x4*y3)<=0.0000001;
}
int main()
{
	freopen("A.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	if(check(p[0],p[1])||check(p[0],p[2])||check(p[1],p[2]))
	{
			cout<<n<<endl;
			return 0;
	}
    else if(n==4)
    {
		if(graham()==4)
		{
			if(judge())
			{
				if(check(p[0],p[1])||check(p[1],p[2])||check(p[0],p[2]))
				{
					cout<<4<<endl;
				}
				else
				cout<<5<<endl;return 0;
			}
		}
		cout<<"oo"<<endl;
    }
    else if(n==5)
    {
		int  llll=graham();
		if(llll==4)
		{
			//for(int i=0;i<top;i++)
			//cout<<s[i].x<<" "<<s[i].y<<endl;
			if(judge()&&check2()) 
			cout<<5<<endl;
			else cout<<"oo"<<endl;
		}
		else if(llll==5)
		{
			//cout<<5;
			if(check(p[0],p[1])||check(p[0],p[2])||check(p[1],p[2]))
			{
				cout<<n<<endl;
			}
			else cout<<"oo"<<endl;
		}
		else cout<<"oo"<<endl;
	}
	else cout<<"oo"<<endl;
	return 0;
}
