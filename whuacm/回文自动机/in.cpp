#include<bits/stdc++.h>
using namespace std;
int n=10000,m=1;
int main()
{
	freopen("1.in","w",stdout);
	for(int i=1;i<=n;i++)
	{
		printf("%c",rand()%m+'a');
	}puts("");
	return 0;
}
