#include <bits/stdc++.h>
using namespace std;
int T;
int n;
const int N=1000005;
struct point//链表
{
	int to,next;
}e[N];
struct node//存放一个位置的 ai*-1   位置   入度
{
	int pos,p,v;
	bool operator < (const node & x) const//安ai*-1 排序
    {
        return pos<x.pos;
    }
}num[N];
int g[N],tot,a[N];
int cnt,ans[N];
priority_queue <node> q;//优先队列

void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
	num[y].v++;//终点入度加一
}

int main()
{
	while(cin>>T)
	{
		while(T--)
		{
			scanf("%d",&n);
			cnt=tot=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d",a+i);
				num[i+1].pos=a[i]*-1;//给n个位置赋值
				num[i+1].p=i+1;
				num[i+1].v=0;
				g[i+1]=0;
			}
			for(int i=0;i<n;i++)
			{
				if(a[i]!=-1)//如果不是-1
				{
					int to=a[i]%n;
					if(to!=i)//并且没在应该在的位置上
					{
						int from=(i-1+n)%n;//就向前连一条边
						add(from+1,i+1);
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(num[i].v==0)//如果入度为零就加入队列
				{
					q.push(num[i]);
				}
			}
			int temp=0;
			while(!q.empty())//求字典序最小的拓扑排序
			{
				node tmp=q.top();
				q.pop();
				ans[++cnt]=tmp.pos*-1;//把答案放入ans【】里
				if(ans[cnt]>-1)temp++;//计算非-1个数
				if(tmp.pos==1)continue;
				for(int j=g[tmp.p];j;j=e[j].next)
				{
					int t=e[j].to;
					num[t].v--;
					if(num[t].v==0)
					{
						q.push(num[t]);
					}
				}
			}
			if(cnt!=n)//如果cnt不为n就是无解
			{
				puts("-1");
			}
			else if(temp==0)//如果非-1个数为0就输出一个空行
			{
				puts("");
			}
			else
			{
				int ok=0;
				for(int i=1;i<=cnt;i++)//输出答案，且不能有行末空格
				{
					if(ans[i]>-1)
					{
						if(ok==0)
						ok=1;
						else printf(" ");
						printf("%d",ans[i]);
					}
				}printf("\n");
			}
		}
	}
	return 0;
}
