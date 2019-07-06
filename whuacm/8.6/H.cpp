#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct point
{
	char a;
	int pos;
}s[200000],t[200000];
int num[200000],sa;
bool cmp(char x,char y)
{
	if(x==y)return false;
	if(x<y&&(x-'A')==(y-'a'))
	return true;
	if(x>y&&(x-'a')==(y-'A'))
	return true;
	return false;
}
int main()
{
	freopen("H.in","r",stdin);
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>s[i].a;
		if(s[i].a<'a')
		{
		    s[i].pos=i;
		}
		else
		{
			sa++;
		    s[i].pos=sa;
		}
	}
	int cnt=0,sum=n,len=n*2,tmp,flag;
	while(cnt<=n+1&&sum>0)
	{
		//for(int i=1;i<=len;i++)
		///cout<<s[i].a;
		//cout<<endl;
		cnt++;
		tmp=1;
		t[1]=s[1];
		flag=0;
		for(int i=2;i<=len;i++)
		{
			if(cmp(s[i].a,s[i-1].a)&&!flag)
			{
				//cout<<"    "<<i<<" "<<tmp<<endl;
				if(s[i].a<s[i-1].a)
				{
					num[s[i].pos]=s[i-1].pos;
				}
				else
				{
					num[s[i-1].pos]=s[i].pos;
				}
				flag=1;
				i++;
				sum--;
				tmp--;
			}
			tmp++;
			t[tmp]=s[i];
		}
		len=tmp;
		for(int i=1;i<=tmp;i++)
		s[i]=t[i];
	}
	if(cnt>n)
	cout<<"Impossible"<<endl;
	else
	{
		for(int i=1;i<=2*n;i++)
		if(num[i])
		cout<<num[i]<<" ";
		cout<<endl;
	}
	return 0;
}
