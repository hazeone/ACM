#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N=100000;
char s[N];
int l1,l2,a1[N],a2[N];
int main()
{
	scanf("%s",s);
	l1=strlen(s);
	for(int i = 1; i <= l1; i++)
		a1[i] = s[l1-i+1] - '0';
	return 0;
}
