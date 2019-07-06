#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
int n=5;
int main()
{
	srand((unsigned)time(0));
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	cout<<rand()%3+2<<endl;
	return 0;
}
