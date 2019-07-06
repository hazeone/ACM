#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
#define LL long long

int jud(int x)
{
	if(x*10%10000>x&&x*100%10000>x&&x*1000%10000)return 1;
	return 0;
}
int main()
{
	for(int i=1;i<=10000;i++)
	{
		if(jud(i))
		{
			cout<<i<<endl;
		}
	}
	return 0;
}

