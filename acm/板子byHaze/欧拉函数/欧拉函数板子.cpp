/******************************/
//朴素做法 srqt(n)
LL Euler(LL x)
{
    LL re=x;
    for(LL i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            re=re/i*(i-1);
            while(x%i==0)
            x/=i;
        }
    }
    if(x>1)
    re=re/x*(x-1);
    return re;
}
/*********************************/
//线性筛+欧拉函数 m+logn

void init()//这段求出了N内的所有素数
{
	isprime[1]=1;
	for(LL i=2;i<N;i++)
	{
		if(!isprime[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt && i*prime[j]<N;j++)
		{
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
LL Euler(LL x)//这里利用上面求出来的 素数来进行求解(也没)快很多
{
	LL ans=x;
	for(int i=1;i<=cnt && prime[i]*prime[i]<=x;i++)
	{
		if(x%prime[i]==0)
		{
			ans=ans/prime[i]*(prime[i]-1);
			while(x%prime[i]==0)
				x/=prime[i];
		}
	}
	if(x>1)
		ans=ans/x*(x-1);
	return ans;
}

/*******************************/
//筛欧拉函数表/质数表 线性筛
const int N=1000010;
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
