#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int ch[1000000][26];
char s[200000];
int n,k,tot;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int node=0;
		int l=strlen(s);
		for(int i=0;i<l;i++)
		{
			int x=s[i]-'a';
			if(ch[node][x])
			node=ch[node][x];
			else
			{
				tot++;
				ch[node][x]=tot;
				node=tot;
			}
		}
	}
}
