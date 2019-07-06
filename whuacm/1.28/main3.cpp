#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
const int MAXM=2010;
int n,m,p,vis[MAXN],has[MAXM];
typedef long long LL;
bitset<2010> s[MAXN];
LL Q[MAXM][MAXM],two[MAXM];
LL quick_pow(LL a,LL b){
	LL ret=1;
	while(b){
		if(b&1)ret=ret*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ret;
}
void init(){
	two[0]=1;
	for(int i=1;i<MAXM;++i)two[i]=two[i-1]*2%p;
	Q[0][0]=1;
	for(int i=1;i<MAXM;++i){
		Q[i][0]=Q[i-1][0];
		for(int j=1;j<=i;++j)Q[i][j]=(Q[i-1][j-1]+two[j]*Q[i-1][j])%p;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	init();
	for(int i=0;i<n;++i){
		string u;
		cin>>u;
		for(int j=0;j<m;++j)s[i][j]=u[j]-'0';
	}
	memset(has,-1,sizeof(has));
	int cnt=0;
	for(int bit=0;bit<m;++bit){
		for(int i=0;i<n;++i){
			if(vis[i])continue;
			for(int j=0;j<bit;++j)if(~has[j]&&s[i][j]==1){
				s[i]^=s[has[j]];
			}
			if(s[i][bit]==1){
				has[bit]=i;
				vis[i]=1;
				break;
			}
		}
	}
	for(int i=0;i<m;++i)if(~has[i])++cnt;
	int x=m-cnt;
	LL ans=0;
	for(int i=0;i<=x;++i)ans=(ans+Q[x][i])%p;
	printf("%lld\n",ans);
	return 0;
}
