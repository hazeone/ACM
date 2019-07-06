#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
#define eps 0.00001
int n;
 double x[N],y[N],dis[N];
double X[N],Y[N];
 double ax,ay;
inline  double D2( double X, double Y)
{
	return X*X+Y*Y;
}
inline  double D( double X, double Y)
{
	return sqrt(D2(X,Y));
}
double R;
void work(int a,int b,int c)
{
	 double A=D2(X[a],Y[a])*Y[b]+Y[a]*D2(X[c],Y[c])+Y[c]*D2(X[b],Y[b])-D2(X[a],Y[a])*Y[c]-D2(X[b],Y[b])*Y[a]-D2(X[c],Y[c])*Y[b];
	 double B=D2(X[b],Y[b])*X[a]+X[c]*D2(X[a],Y[a])+X[b]*D2(X[c],Y[c])-X[a]*D2(X[c],Y[c])-X[b]*D2(X[a],Y[a])-X[c]*D2(X[b],Y[b]);
	 double C=X[a]*Y[b]+Y[a]*X[c]+X[b]*Y[c]-X[a]*Y[c]-X[b]*Y[a]-X[c]*Y[b];
	ax=A/C/2.0;
	ay=B/C/2.0;
	R = D(X[a] - ax, Y[a] - ay);
}

bool check()
{
	int num = 0;
	for(int i=1;i<=n;i++)
	{
		dis[i]=D(ax-X[i],ay-Y[i]);
		if (abs(dis[i] - R) < eps) num ++;
	}
	return num >= (n + 1) / 2;
}
int main()
{
	srand(time(0));
	int T;
	while(~scanf("%d",&T))
	{
		while(T--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			{
				scanf("%lf%lf",X+i,Y+i);
			}
			if(n==1)
			{
				printf("%.6f %.6f 0\n",X[1],Y[1]);
				continue;
			}
			if(n<=4)
			{
				double mx=(X[1]+X[2])/2.0;
				double my=(Y[1]+Y[2])/2.0;
				printf("%.6f %.6f %.6f\n",mx,my,D(X[1]-mx,Y[1]-my));
				continue;
			}
			while(1)
			{
				int id[3];
				for(int i=0;i<3;i++)
				{
					id[i]=rand() * rand() %n + 1;
					int ok=1;
					for(int j=0;j<i;j++)
					if(id[i]==id[j])
					ok=0;
					if(ok==0)i--;
				}
				work(id[0],id[1],id[2]);
				if(check())break;
			}
			if(abs(ax)<0.000001)ax=0;
			if(abs(ay)<0.000001)ay=0;
			double o1=ax,o2=ay,o3=R;
			printf("%.6f %.6f %.6f\n",o1,o2,o3);
		}
	}
	return 0;
}
