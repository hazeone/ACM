#include<bits/stdc++.h>
using namespace std;

int T,a[200000],k,pos[200000],v[200000],n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			pos[a[i]]=i;
			v[i]=0;
		}
		if(k>=2)
		{
			k--;
			int k0=k;
			if(a[1]<=k0)k0++;
			cout<<k0<<endl;
			for(int i=1;i<=n;i++)
			{
				if(v[i]==0)
				{
					if(i==1)
					printf("1");
					else printf(" %d",i);
					v[i]=1;
					if(pos[i]==1&&i>k)k0++;
					for(int j=pos[i]+1;j<=n;j++)
					{
						int x=j-pos[i];
						if(v[a[j ]]==1)break;
						if(a[j]==i+x)k0++;
						else if(a[j]<=k0)break;
						printf(" %d",a[j]);
						v[a[j]]=1;
					}
				}
			}cout<<k0<<endl;
		}
		else 
		{
			printf("%d",a[1]);
			for(int i=2;i<=n;i++)
			printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
/*
6 3
1 2 3 6 5 4
 */
