#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
long long sl,sr,tl,smach;
int n,T;
char s[200000];
int main()
{
	freopen("1012.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int flag=0;
		sl=sr=tl=smach=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			char x;
			cin>>s[i];
			x=s[i];
			if(x=='(')
			{
				sl++;
				tl++;
				if(s[i-1]==')'&&s[i-2]==')')
				flag=1;
			}
			else
			{
				sr++;
				if(tl>0)
				{
					tl--;
					smach++;
				}
			}
		}
		if(sl!=sr)
		{
			printf("No\n");
			continue;
		}
		if(n>2)
		{
			if(n&1)
			{
				printf("No\n");
			}
			else
			{
				if(n==smach*2+2||n==smach*2||(flag&&n==smach*2+4))
				printf("Yes\n");
				else printf("No\n");
			}
		}
		else
		{
			if(sl==1&&sr==1&&smach==0)
			{
				printf("Yes\n");
			}
			else
			printf("No\n");
		}
	}
	return 0;
}
