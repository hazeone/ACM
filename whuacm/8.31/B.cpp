#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,pos;
int main()
{
	freopen("B.in","r",stdin);
	scanf("%d%d",&n,&pos);
	int flag=0,flag2=0,sl=0,sr=0;int x,k;//flag dan flag2 chengdui
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&k);
		if(x>pos&&!flag)
		{
			if(sl)
			{
				sl--;
				flag=1;
			}
			else 
			{
				sr++;//cout<<i<<endl;
			}
		}
		if(k==0)
		{
			sl++;
			//cout<<i<<"    "<<sl<<endl;
		}
		else
		{
			if(sl)
			{
				sl--;
				if(sl==0&&!flag)
				{
					flag2=1;
				}
			}
			else 
			{
				sr++;//cout<<i<<"!!!!"<<endl;
			}
		}
	}
	if(!flag)
	{
		if(sl)
		{
			sl--;
			flag=1;
		}
		else 
		{
			sr++;//cout<<n<<endl;
		}
			
	}
	if(sl>0)
	cout<<-1<<endl;
	else if(sl==0&&flag2)cout<<-1<<endl;
	else cout<<sr<<endl;
	return 0;
}
