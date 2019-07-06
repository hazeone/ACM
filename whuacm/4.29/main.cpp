#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n;
int m,a1,a2,a3;
char s[100100];
int cnt[100],b[4];
int tchar(char c)
{
	if(c<='z'&&c>='a')return c-'a'+26;
	return c-'A';
}
int getans()
{
	memset(cnt,0,sizeof(cnt));
	int mx=0;
	for(int i=0;i<m;i++)
	{
		cnt[tchar(s[i])]++;
	}
	for(int i=0;i<52;i++)
	{
		if(cnt[i]+n<=m)
		mx=max(mx,cnt[i]+n);
		else{
			int tt=(n+cnt[i]-m);
			mx=max(mx,m-(tt&1));
		}
	}
	return mx;
}
int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%s",s);
		m=strlen(s);
		a1=getans();
		b[0]=a1;
		scanf("%s",s);
		m=strlen(s);
		a2=getans();
		b[1]=a2;
		scanf("%s",s);
		m=strlen(s);
		a3=getans();
		b[2]=a3;
		sort(b,b+3);
		cout<<a1<<" "<<a2<<" "<<a3<<endl;
		if(b[1]==b[2])
		{
			printf("Draw\n");
			continue;
		}
		if(b[2]==a1)
		{
			printf("Kuro\n");
			continue;
		}
		if(b[2]==a2)
		{
			printf("Shiro\n");
			continue;
		}
		if(b[2]==a3)
		{
			printf("Katie\n");
		}
	}
    return 0;
}
