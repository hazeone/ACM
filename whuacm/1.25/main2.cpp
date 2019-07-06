#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
#define LL long long
struct point 

{
	LL v1,v2;
}c[200000];
int n,na,nb;
LL a[200000],b[200000];
LL ans=0;
bool cmp(point A,point B)
{
	if(A.v1==B.v1)return A.v2<B.v2;
	return A.v1>B.v1;
}
bool cmp2(point A,point B)
{
	return A.v2>B.v2;
}
int main()
{
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=1;i<=n;i++){
	
		scanf("%lld",a+i);
		if(a[i]<0)a[i]=0;
		ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",b+i);
		if(b[i]<0)b[i]=0;
		c[i].v1=b[i]-a[i];
		c[i].v2=-a[i];
	}
	sort(c+1,c+1+n,cmp);
	//for(int i=1; i<=n;i++)
	//{
	//	cout<<c[i].v1<<" "<<c[i].v2<<endl;
	//}
	for(int i=1;i<=nb;i++)
	{
		ans+=c[i].v1;
	}
	sort(c+1+nb,c+1+n,cmp2);
	//for(int i=1; i<=n;i++)
	//{
	//	cout<<c[i].v1<<" "<<c[i].v2<<endl;
	//}
	for(int i=1;i<=n-na-nb;i++)
	{
		ans+=c[nb+i].v2;
	}
	printf("%lld\n",ans);
	return 0;
}

