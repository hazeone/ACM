#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1005;
LL mod=1e9+7;
struct mat
{
	int l,r;
	LL a[N][N];
}A,B,C;
LL n,m;
void clr(mat & X)
{
	for(int i=1;i<=X.l;i++)
	for(int j=1;j<=X.r;j++)
	X.a[i][j]=0;
}
mat operator *(mat X,mat Y)
{
	mat Z;
	Z.l=X.l;
	Z.r=Y.r;
	for(int i=1;i<=Z.l;i++)
	for(int j=1;j<=Z.r;j++)
	Z.a[i][j]=0;
	for(int i=1;i<=Z.l;i++)
	{
		for(int k=1;k<=X.r;k++)
		{
			if(X.a[i][k]!=0)
			{
				for(int j=1;j<=Z.r;j++)
				{
					Z.a[i][j]=(Z.a[i][j]+X.a[i][k]*Y.a[k][j]%mod)%mod;
				}
			}
		}
	}
	return Z;
}
void out(mat X)
{
	cout<<"***********"<<endl;
	cout<<X.l<<" "<<X.r<<endl;
	for(int i=1;i<=X.l;i++)
	{
		for(int j=1;j<=X.r;j++)
		cout<<X.a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void work(LL b)
{
	while(b)
	{
		if(b&1)
		{
			C=C*B;
		}
		B=B*B;
		b=b>>1;
	}
	A=A*B;
	printf("%lld\n",A.a[1][n]);
}
int main()
{
	while(~scanf("%lld%lld",&n,&m))
	{
		A.l=1;
		A.r=n;
		B.l=B.r=C.r=C.l=n;
		clr(B);
		clr(C);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&A.a[1][i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&B.a[n-i+1][n]);
		}
		for(int i=2;i<=n;i++)
		{
			B.a[i][i-1]=1;
		}
		for(int i=1;i<=n;i++)
		C.a[i][i]=1;

		out(A);
		out(B);
		out(C);
		B=B*B;
		out(B);
		if(m<=n)
		{
			printf("%lld\n",A.a[1][m]);
		}
		else
		{
			work(m-n);
		}
	}
	return 0;
}
