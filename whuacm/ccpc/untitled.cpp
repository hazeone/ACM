#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n;
const LL MOD=998244353;
const int N = 400005;
const int g=3;//原根
int len;
LL A[N];
LL a[N],b[N],wn[30];
LL q_pow(LL x,LL y,LL P)
{
    LL ans=1;
    while(y>0)
    {
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}
void init()
{
    for(int i=0;i<21;i++)
    {
        int t=1<<i;
        wn[i]=q_pow(g,(MOD-1)/t,MOD);
    }
}
///雷德算法，2^M=len，将第i位的数与“i的二进制反转之后的位”的数交换
void rader(LL F[],int len)
{
    int j=len/2;///模拟二进制反转进位的的位置
    for(int i=1;i<len-1;i++)
    {
        if(i<j)swap(F[i],F[j]);///该出手时就出手
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k>>=1;
        }
        if(j<k)j+=k;
    }
}
void NTT(LL F[],int len,int t)
{
    int id=0;
    rader(F,len);
    for(int h=2;h<=len;h<<=1)
    {
        id++;
        for(int j=0;j<len;j+=h)
        {
            LL E=1;
            for(int k=j;k<j+h/2;k++)
            {
                LL u=F[k];
                LL v=(E*F[k+h/2])%MOD;
                F[k]=(u+v)%MOD;
                F[k+h/2]=((u-v)%MOD+MOD)%MOD;
                E=(E*wn[id])%MOD;
            }
        }
    }
    if(t==-1)
    {
        for(int i=1;i<len/2;i++)swap(F[i],F[len-i]);
        LL ni=q_pow(len,MOD-2,MOD);
        for(int i=0;i<len;i++)F[i]=(F[i]%MOD*ni)%MOD;
    }
}

void work()///卷积，点乘，插值
{
    NTT(a,len,1);
    NTT(b,len,1);
    for(int i=0;i<len;i++)
        a[i]=(a[i]*b[i])%MOD;
    NTT(a,len,-1);
}
int main()
{
    init();
    /*
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        //sc(n);
        len=1;
        while(len<=2*n)
            len<<=1;

　　　　　　　这部分就是你对公式的变形并把他转化为卷积形式，分别存在a[],b[]里
		work();
	}*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	scanf("%lld",a+i);
	for(int j=0;j<=m;j++)
	scanf("%lld",b+j);
	int tl=m+n+2;
	len=1;
	while(len<=tl)
	{
		len<<=1;
	}
	work();
	for(int i=0;i<tl-1;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
