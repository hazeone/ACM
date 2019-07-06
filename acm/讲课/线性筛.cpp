#include<bits/stdc++.h>
using namespace std;
const int N=100;
int num[N],flag[N],cnt;
int main()
{
	flag[1]=1;
	for(int i=2;i<N;i++)
	{
		if(flag[i]==0)
			num[++cnt]=i;
		for(int j=1;j<=cnt&&num[j]*i<N;j++)
		{
			//cout<<num[j]*i<<" ";
			flag[num[j]*i]=1;
			if(i%num[j]==0)break;
		}
		//cout<<endl;
	}
	for(int i=1;i<=cnt;i++)
	cout<<num[i]<<endl;
	return 0;
}
