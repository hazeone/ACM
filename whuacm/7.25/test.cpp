#include<cstdio>
#include<cstring>

const int mod=1e8+7;
const int maxn=1005;

typedef long long ll;
int a[maxn];
ll dp[maxn][maxn];
int g[maxn][maxn];

int gcd__(int n,int m){
    if(m==0)return n;
    return gcd__(m,n%m);
}
void scanf_(int&data){
    data=0;
    char ch;
    while((ch=getchar())&&(ch<'0'||ch>'9')){

    }
    do{
        data=data*10+ch-'0';
        ch=getchar();
    }while(ch>='0'&&ch<='9');
}
int main(){

    int T;
    for(int i=1;i<=1000;++i){
        for(int j=i;j<=1000;++j){
            g[j][i]=g[i][j]=gcd__(i,j);
        }
    }
    scanf_(T);
    while(T--){
        int n;
        scanf_(n);
        for(int i=0;i<n;++i){
            scanf_(a[i]);
        }
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;++i){
            dp[i][a[i]]++;
            for(int j=1;j<=1000;j++){
                dp[i+1][j]+=dp[i][j];
                int v_=a[i+1];
                dp[i+1][g[v_][j]]+=dp[i][j];
                if(dp[i+1][j]>=mod)dp[i+1][j]%=mod;
                if(dp[i+1][g[v_][j]]>=mod)dp[i+1][g[v_][j]]%=mod;
            }
        }
        ll ans=0;
        for(int i=1;i<=1000;++i){
            if(!dp[n][i])continue;
            ans+=((i*dp[n][i])%mod);
            if(ans>=mod)ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
