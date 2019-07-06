#include<bits/stdc++.h>
using namespace std;
#define LL long long

struct node
{
    int a[5][5];
    int val;
}a[5][5],b[5];
struct que
{
    int val[5];
}q[500000];
char s[20][20];
int c[5][17],v[5][5];
int tr(char x)
{
    if(x<='9'&&x>='0')return x-'0';
    return x-'A'+10;
}
void init(int x,int y)
{
    int tx=(x-1)*4;
    int ty=(y-1)*4;
    for(int i=1;i<=4;i++)
    for(int j=1;j<=4;j++)
    {
        a[x][y].a[i][j]=tr(s[tx+i][ty+j]);
    }
    a[x][y].val=0;
}
node trans(node A)
{
    if(A.val==0)
    return A;
    node B;
    B.val=0;
    if(A.val==1)
    {
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            B.a[j][4-i+1]=A.a[i][j];
        }
    }
    if(A.val==2)
    {
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            B.a[4-i+1][4-j+1]=A.a[i][j];
        }
    }
    if(A.val==3)
    {
        for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
        {
            B.a[4-j+1][i]=A.a[i][j];
        }
    }
    return B;
}
int check(int x,int now)
{
    if(now==0)
    {
        for(int i=1;i<=4;i++)
        b[i]=trans(a[x][i]);
    }
    else
    {
        for(int i=1;i<=4;i++)
        b[i]=trans(a[i][x]);
    }
    for(int i=1;i<=4;i++)
    for(int j=0;j<16;j++)
    c[i][j]=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                int t;
                if(now==0)
                {
                    t=b[i].a[j][k];
                }
                else
                {
                    t=b[i].a[k][j];
                }
                if(c[j][t]==1)return 0;
                c[j][t]=1;
            }
        }
    }
    return 1;
}
int vv[5],br;
void bfs(int x,int now)
{
    int head=0,tail=1;
    for(int i=1;i<=4;i++)
    q[1].val[i]=0;
    while(head<tail)
    {
        head++;
        if(now==0&&head==1)
        {
            for(int i=1;i<=4;i++)
            a[x][i].val=q[head].val[i];
            if(check(x,now))
            {
				for(int i=1;i<=4;i++)
				vv[i]=q[head].val[i];
				break;
			}
        }
        if(now==1&&head==1)
        {
            for(int i=1;i<=4;i++)
            a[i][x].val=q[head].val[i];
            if(check(x,now))
            {
				for(int i=1;i<=4;i++)
				vv[i]=q[head].val[i];
				break;
			}
        }
        br=0;
        for(int i=1;i<=4;i++)
        {
            if(q[head].val[i]<3)
            {
                tail++;
                for(int j=1;j<=4;j++)
                {
                    q[tail].val[j]=q[head].val[j];
                    if(j==i)
                    q[tail].val[j]++;
                    if(now==0)
                    vv[j]=a[x][j].val=q[tail].val[j];
                    else vv[j]=a[j][x].val=q[tail].val[j];
                }
                if(check(x,now))
                {
					br=1;
					break;
			    }
            }
        }
        if(br)break;
    }
    if(now==0)
    {
        for(int i=1;i<=4;i++)
        {
            v[x][i]=vv[i];
        }
    }
    else
    {
        int sum1=0,sum2=0;
        for(int i=1;i<=4;i++)
        {
            int s=0;
            for(int j=1;j<=4;j++)
            {
                s+=v[i][j];
            }
            if(vv[i]==0)
            {
                sum1+=s;
                sum2+=8-s;
            }
            else
            {
                sum1+=8-s;
                sum2+=s;
            }
        }
        printf("%d\n",min(sum1,sum2));
    }
}
int main()
{
    int T;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            for(int i=1;i<=16;i++)
            {
                scanf("%s",s[i]+1);
            }
            //clr();
            for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
            init(i,j);
            for(int i=1;i<=4;i++)
            {
                bfs(i,0);
            }
            for(int i=1;i<=4;i++)
            {
                for(int j=1;j<=4;j++)
                {
                    a[i][j].val=v[i][j];
                    a[i][j]=trans(a[i][j]);
                }
            }
            //for(int i=1;i<=4;i++)
            //{
				//for(int j=1;j<=4;j++)
				//cout<<v[i][j]<<" ";
				//cout<<endl;
			//}
            bfs(1,1);
        }
    }
    return 0;
}
