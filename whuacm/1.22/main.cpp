#include<bits/stdc++.h>
using namespace std;
int n,k,a[400000][4],c[100000];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	cin>>n>>k;double cc=clock();
	int j=1,tmp,mx;
	for(int i=1;i<=400000;i++)
	{
		tmp=j;int v=0,vv=0;
		while(1)
		{
			if(c[tmp]<4)
			{
				v=0;
				for(int l=1;l<=c[tmp];l++)
				{
					if(gcd(a[tmp][l],i)!=1)
					{
						v=1;
						break;
					}	
				}
				if(!v)
				{
					a[tmp][++c[tmp]]=i;
					vv=1;
				}
			}
			tmp++;
			if(vv||tmp>n)break;
		}
		if(c[j]==4)j++;
		if(j>n)
		{
			mx=i;
			break;
		}
	}
	printf("%d\n",mx*k);
	for(int l=1;l<=n;l++)
	printf("%d %d %d %d\n",a[l][1],a[l][2],a[l][3],a[l][4]);
/*	while(~scanf("%d",&n))
	{
	}*/
	cout<<cc-clock()<<endl;
	return 0;
}
