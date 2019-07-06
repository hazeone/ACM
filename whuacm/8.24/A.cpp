#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
long long a[5000],b[5000],sk[1000002];
//~ | & ( )
char s[1000002],t[1000002];
long long getans(char ss[],int n)
{
	int top=0;
	for(int i=0;i<n;i++)
	{
		if(ss[i]==' ')continue;
		if(ss[i]=='~')
		{
			top++;
			sk[top]=-1000;
		}
		else if(ss[i]=='V')
		{
			top++;
			sk[top]=-2000;
		}
		else if(ss[i]=='^')
		{
			top++;
			sk[top]=-3000;
		}
		else if(ss[i]=='(')
		{
			top++;
			sk[top]=-4000;
		}
		else if(ss[i]==')')
		{
			if(sk[top]==-4000)
			{
				top--;
				continue;
			}
			if(sk[top-1]==-4000)
			{
				sk[top-1]=sk[top];
				top--;
			}
			while(sk[top-1]!=-4000&&top>1)
			{
					if(sk[top-1]==-1000)
					{
						sk[top-1]=(~sk[top]);
						top--;
						continue;
					}
					if(sk[top-1]==-2000)
					{
						top-=2;
						sk[top]=(sk[top]|sk[top+2]);
						continue;
					}
					if(sk[top-1]==-3000)
					{
						top-=2;
						sk[top]=(sk[top]&sk[top+2]);
						continue;
					}
			}
		}
		else
		{
			int tt=ss[i];
			if(sk[top]==-1000)
			{
				sk[top]=(~a[tt]);
				if(sk[top-1]==-2000)
				{
					top-=2;
					sk[top]=(sk[top]|sk[top+2]);
				}
				if(sk[top-1]==-3000)
				{
					top-=2;
					sk[top]=(sk[top]&sk[top+2]);
				}
				continue;
			}
			if(sk[top]==-2000)
			{
				sk[top-1]=(sk[top-1]|a[tt]);
				top--;continue;
			}
			if(sk[top]==-3000)
			{
				sk[top-1]=(sk[top-1]&a[tt]);
				top--;continue;
			}
			sk[++top]=a[tt];
		}
	}
	return sk[top];
}
int main()
{
	freopen("A.in","r",stdin);
	srand(time(0));
	while(gets(s)!=NULL)
	{
		gets(t);
		int ls=strlen(s),lt=strlen(t);
		int flag=1;
		for(int k=0;k<100;k++)
		{
			for(int i=64;i<=123;i++)
			a[i]=rand();
			long long ans1=getans(s,ls);
			long long ans2=getans(t,lt);
			if(ans1!=ans2)
			{
				flag=0;
				break;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}
