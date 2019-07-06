/*
 * 统计s有多少个不同的子串
 */
#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
const int M=26;
#define LL long long

char s[N];
int n;

struct sam{
	int cnt,last;
	int link[N*2],trans[N*2][M],mx[N*2],mn[N*2];
	sam()
	{
		last=cnt=1;
	}
	void add(int c)
	{
		int p=last,np=last=++cnt;
		mx[np]=mx[p]+1;//
		mn[np]=-1;
		while(!trans[p][c]&&p)trans[p][c]=np,p=link[p];

		if(!p){
			link[np]=1;
			mn[np]=1;
		}
		else
		{
			int q=trans[p][c];
			if(mx[p]+1==mx[q])
			{
				link[np]=q;
				mn[np]=mx[q]+1;
			}
			else
			{
				int nq=++cnt;
				mx[nq]=mx[p]+1;
				memcpy(trans[nq],trans[q],sizeof(trans[q]));
				link[nq]=link[q];
				link[np]=link[q]=nq;
				mn[q]=mx[nq]+1;
				mn[np]=mx[nq]+1;
				while(trans[p][c]==q)trans[p][c]=nq,p=link[p];
				mn[nq]=mx[link[nq]]+1;
			}
		}
	}
	void slove()
	{
		long long ans=0;
		for(int i=1;i<=cnt;i++){
			ans=ans+mx[i]-mx[link[i]];
		}
		printf("%lld\n",ans);
	}
	/*void pre()
	{
		for(int i=0;i<=n;i++)v[i]=0;
		for(int i=1;i<=cnt;i++)v[mx[i]]++;
		for(int i=1;i<=n;i++)v[i]+=v[i-1];
		for(int i=1;i<=cnt;i++)pos[v[mx[i]]--]=i;
	}*/
}SAM;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)SAM.add(s[i]-'a');
	SAM.slove();
	return 0;
}
