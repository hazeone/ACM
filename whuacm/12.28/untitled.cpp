#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct point
{
	LL l,r;
}a[200020];
LL cnt[200020];
bool cmp(point A,point B)
{
	if(A.l==B.l)return A.r<B.r;
	return A.l<B.l;
}
priority_queue<vector<LL>, less<LL> > q;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld",&a[i].l,&a[i].r);
			cnt[i]=0;
		}
		sort(a+1,a+1+n,cmp);
		int now=1,t=2;
		LL cur=a[1].l;
		q.push(a[1].r);
		while(!(q.empty()&&t>n))
		{
			LL x=q.top();
			if(t<=n)
			{
				if(a[t].l<=x)
				{
					cnt[now]+=a[t].l-cur;
					now++;
					cur=a[t].l;
					q.push(a[t].r);
					t++;
				}
				else
				{
					cnt[now]+=x-cur+1;
					now--;
					q.pop();
					cur=x
				}
			}
			else
		}
	}
	return 0;
}
