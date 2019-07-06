#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int n;
struct sam{
	int cnt,last;
	map<int,int>trans[N*2];
	int link[N*2],mx[N*2],mn[N*2];
	long long ans;
	sam()
	{
		last=cnt=1;
	}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		mx[np]=mx[p]+1;//
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];
		if(!p)link[np]=1;
		else
		{
			int q=trans[p][c];
			if(mx[p]+1==mx[q])
			{
				link[np]=q;
			}
			else
			{
				int nq=++cnt;
				mx[nq]=mx[p]+1;
				trans[nq]=trans[q];
				link[nq]=link[q];
				link[np]=link[q]=nq;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
			}
		}
		if(link[np]==1)ans+=mx[np];
		else ans+=(mx[np]-mx[link[np]]);
		printf("%lld\n",ans);
	}
}SAM;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		SAM.add(x);
	}
}
