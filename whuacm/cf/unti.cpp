#include<bits/stdc++.h>
using namespace std;
const int inf=1061109567;
char s[1005];int n;
int mp[5][1010],w[6],mat[6],f[1005][1<<12],bin[5][5];
void work() {
	int s0=0,lim=1;
	for(int j=1;j<=3;++j)
		for(int i=1;i<=4;++i)
			bin[i][j]=lim,lim<<=1;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=3;++j)
			if(mp[i][j]) s0|=bin[i][j];
	f[1][s0]=0;
	for(int j=1;j<=n;++j) {
		int now=0;
		for(int i=1;i<=4;++i) if(mp[i][j+3]) now|=bin[i][1];
		for(int zt=0;zt<lim;++zt) {
			if(f[j][zt]==inf) continue;
			f[j+1][lim-1]=min(f[j+1][lim-1],f[j][zt]+w[4]);
			for(int a=0;a<=3;++a)
			  for(int b=0;b<=3;++b)
			    for(int c=0;c<=2;++c)
				  for(int d=0;d<=1;++d) {
				  int fy=w[a]+w[b]+w[c]+w[d];
				  int kl=mat[a]|(mat[b]<<1)|(mat[c]<<2)|(mat[d]<<3);
				  if(((zt|kl)&15)==15) {
				    int nxt=((zt|kl)>>4)|(now<<8);
				    f[j+1][nxt]=min(f[j+1][nxt],f[j][zt]+fy);
				  }
			 }
		}
	}
	printf("%d\n",f[n+1][lim-1]);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=4;++i) scanf("%d",&w[i]);
	for(int i=0;i<4;++i) {
		scanf("%s",s);
		for(int j=0;j<n;++j) mp[i+1][j+1]=(s[j]=='.');
	}
	for(int j=n+1;j<=n+3;++j)
		for(int i=1;i<=4;++i) mp[i][j]=1;
	mat[1]=1,mat[2]=51,mat[3]=1911;
	memset(f,0x3f,sizeof(f));work();
    return 0;
}
