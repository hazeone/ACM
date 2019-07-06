#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
long double n,a,sum,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ans+=i*a-sum+m[(int)(a+1)]-m[(int)(a-1)];
		sum+=a;
		m[(int)a]++;
	}
	printf("%.0Lf",ans);
	return 0;
}
