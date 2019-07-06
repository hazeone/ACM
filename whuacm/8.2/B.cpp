#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int N=220;

double p[N], f[N];
int a[N],T,n,op[N];
int main() {
	while (~ scanf ("%d",&n)) {
		double ans=0;
		for (int i=0; i<=n; i++)
			scanf ("%d",&a[i]);
		char c;
		for (int i=1; i<=n; i++) {
			f[0] = 0;
			scanf ("%c", &c);
			while (c != '^' && c != '|' && c != '&')
				scanf ("%c", &c);
			if (c=='|')
				op[i]=1;
			if (c=='&')
				op[i]=2;
			if (c=='^')
				op[i]=3;
		}
		for (int i=1; i<=n; i++)
			scanf ("%lf",&p[i]);
		for (int k=0; k<=20; k++) {
			if (a[0] & (1 << k))
				f[0] = 1;
			else
				f[0] = 0;
			for (int i=1; i<=n; i++) {
				if (a[i] & (1 << k)) {
					if (op[i]==1)
						f[i] = f[i-1] + (1.0 - f[i-1]) * (1.0 - p[i]);
					else if (op[i]==2)
						f[i]=f[i-1];
					else
						f[i] = (1.0 - f[i-1]) * (1.0 - p[i]) + f[i-1] * p[i];
				} else {
					if (op[i]==1)
						f[i]=f[i-1];
					else if (op[i]==2)
						f[i]=f[i-1] * p[i];
					else
						f[i]=f[i-1];
				}
			}
			ans += (double) (1 << k) * f[n];
		}
		printf ("Case #%d:\n%.6lf\n", ++ T, ans);
	}
	return 0;
}
