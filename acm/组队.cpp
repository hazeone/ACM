#include<bits/stdc++.h>
using namespace std;
struct P
{
	int pos,num;
}a[100010];
bool cmp(P A,P B){
	return A.num<B.num;
}
void get(int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i].pos=i;
		a[i].num=rand();
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i].pos);
	puts("");
}
int main()
{
	srand(951572015);
	int n;
	cin>>n;
	get(n);
	return 0;
}
