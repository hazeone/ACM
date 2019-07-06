#include<cstdio>
#include<cmath>
#include<climits>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define fd(x,y,z) for(int x=y;x>=z;x--)

int main()
{
	while(~scanf("%d",&n))
	{
		memset(rec,0,sizeof(rec));
		memset(b,0,sizeof(b));
		f(i,1,n)
		{
			scanf("%s%d%d",s,%x,%y);
			x--;
			y--;
			x0=s[0]-'A';
			x1=s[1]-'A';
			a[i].x=x;
			a[i].y=y;
			a[i].x0=x0;
			a[i].x1=x1;	
			if(y==2)
			{
				rec[x][x0]=1;
				rec[x][x1]=1;
			}
			else if(y==0)
			{
				rec[1-x][x0]=1;
				rec[1-x][x1]=1;
			}
		}
		ok=1;
		f(i,1,n)if(a[i].y==1)
		{
			sum=0;
			x=a[i].x;
			if(rec[x][a[i].x0])sum++;
			if(rec[x][a[i].x1])sum++;
			if(sum==2)ok=0;
			else if(sum==1)
			{
				if(rec[x][a[i].x0])rec[1-x][a[i].x0]=1;
				else rec[1-x][a[i].x1]=1;
			}
			else
			{
				sum=0;
				if(rec[1-x][a[i].x0])sum++;
				if(rec[1-x][a[i].x1])sum++;
				if(sum==2)ok=0;
				else if(sum==0)b[i]=1;
			}
		}
		
		f(i,0,25)if(rec[0][i] || rec[1][i])
		{
			if(rec[0][i]&&rec[1][i])ok=0;
			else tot--; 
		}
		if(tot<3 || ok==0)printf("0\n");
		else
		{
			f(i,0,25)f(r,i+1,25)f(s,r+1,25)if(!rec[0][i] && !rec[1][i] && !rec[0][r] && !rec[1][r] && !rec[0][s] && !rec[1][s])
			{
				f(q,0,25)t_rec[0][q]=rec[0][q],t_rec[1][q]=rec[1][q];
				f(q,1,n)t_b[q]=b[q];
				t_tot=tot;
				f(q,1,n)if(b[q])
				{
					x=a[q].x;
					if(a[q].x0==i || a[q].x0==r || a[q].x0==s)
					{
						t_rec[x][a[q].x1]=1;
						t_b[q]=1;
					}
				}
				tot=26;
				ok=1;
				f(q,0,25)if(rec[0][q]||rec[1][q])
				{
					if(rec[0][q]&&rec[1][q])ok=0;
					else tot--;
				}
				if(!ok)continue;
				memset();
				f(q,1,n)if(t_b[q])
				{
					ad((a[q].x0+1)*2-a[q].x,(a[q].x1+1)*2-a[q].x);
					ad((a[q].x1+1)*2-a[q].x,(a[q].x0+1)*2-a[q].x);
				}
				memset(v,0,sizeof(v));
				ok=1;
				f(q,1,52)if(!v[q])
				{
					dfs(q);
					if(!ok)break;
				}
				if(ok)ans+=
			}
		}
	}
    return 0;
}
