#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
string a[100000];
int n;
int main()
{
	freopen("1.in","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		cout<<endl;
	}
	string s;
	s=a[1]+"dddd"+a[2];
	cout<<s<<endl;
	return 0;
}
