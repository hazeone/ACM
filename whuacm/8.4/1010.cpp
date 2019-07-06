#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long T,a,b,f[70];
int main()
{freopen("1010.in","r",stdin);
	f[0]=1;
	for(int i=1;i<=32;i++)
	{
		f[i]=(f[i-1]<<1);
	}
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		if(a<=b)
		printf("%lld\n",b-a);
		else
		{
			long long ans=(a-b)*2-1,sum=a-b,tmp=0,tmp1=0,cnt=0;
			int pos=1;
			while(f[pos]-1<=sum)pos++;
			if(pos+b<ans)ans=pos+b;
			while(sum)
			{
				int j=1;
				while(f[j]-1<=sum)j++;
					tmp+=j+f[j]-1-sum;
					if(cnt<=f[j]-1-sum)
					{
						tmp-=cnt;
					}
					else
					{
						tmp=tmp-(f[j]-1-sum);
					}
					if(tmp<ans)ans=tmp;
					tmp=tmp1;
				tmp+=j;
				tmp1=tmp;
				sum=sum-f[j-1]+1;
				cnt++;
			}
			printf("%lld\n",min(tmp-1,ans));
		}
	}
	return 0;
}
