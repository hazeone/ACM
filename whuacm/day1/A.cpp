#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL mod=1000000007;
LL inf=1e9+7;
const int N=1010;
int prime[N+1],isprime[N+1];//prime是素数数组，isprime为标记不是素数的数组
int tot,phi[N+1];//phi为φ(),tot为1~i现求出的素数个数
void getphi()
{
    phi[1]=1;//φ(1)=1
    isprime[1]=1;
    for(int i=2;i<=N;i++)//从2枚举到N
    {
        if(!isprime[i])//如果是素数
        {
            prime[++tot]=i;//那么进素数数组，指针加1
            phi[i]=i-1;//根据性质1所得
		}
        for(int j=1;j<=tot&&i*prime[j]<=N;j++)//从现求出素数枚举
        {
            isprime[i*prime[j]]=1;//标记i*prime[j]不是素数
            if(i%prime[j]==0)//φ(p*i)=p*φ(i)（当p%i==0时）
            {
                phi[i*prime[j]]=phi[i]*prime[j];break;
            }
            else phi[i*prime[j]]=phi[i]*phi[prime[j]];//φ(p*i)=(p-1)*φ(i) (当p%i!=0时)
        }
    }
}
int main()
{
    getphi();
    for(int i=1;i<N;i++){
        cout<<i<<":phi ( "<<phi[i]<<" )"<<endl;//输出phi(i)
    }
    return 0;
}
