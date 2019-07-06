#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n;
long long a[1000][1000];
int main()
{freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>a[i][j];
	long long s1=0,s2=0,s3=0,s4=0,s5=0,s6=0;
	int flag1=0,flag2=0,fff=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][i]==0)
		{
			flag1=1;
		}
		s1+=a[i][i];
		if(a[i][n-i+1]==0)
		{
			flag2=1;
		}
		s2+=a[i][n-i+1];
	}
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(int i=1;i<=n;i++)
	{
		long long tmp=0;
		for(int j=1;j<=n;j++)
		{
			tmp+=a[i][j];
		}
		if(tmp==s3){cnt1++;continue;}
		if(tmp==s4){cnt2++;continue;}
		if(s3==0){s3=tmp;cnt1++;continue;}
		if(s3>0&&s4==0){s4=tmp;cnt2++;continue;}
		if(s3>0&&s4>0){//cout<<s3<<s4<<tmp<<"!!!!"<<endl;
			fff=1;break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long tmp=0;
		for(int j=1;j<=n;j++)
		{
			tmp+=a[j][i];
		}
		if(tmp==s5){cnt3++;continue;}
		if(tmp==s6){cnt4++;continue;}
		if(s5==0){s5=tmp;cnt3++;continue;}
		if(s5>0&&s6==0){s6=tmp;cnt4++;continue;}
		if(s5>0&&s6>0){
			fff=1;break;
		}
	}
	if(cnt1+cnt2!=n||cnt3+cnt4!=n)
	fff=1;
	if((cnt1>1&&cnt2>1)||(cnt3>1&&cnt4>1)||(cnt1*cnt2)==0||(cnt3*cnt4==0))fff=1;
	if(s3<s4)swap(s3,s4);
	if(s5<s6)swap(s5,s6);
	long long x=s5-s6;
	if(s3-s4!=x||s3!=s5||x<=0)
	{
		fff=1;
	}
	if(flag1)
	s1+=x;
	if(s1!=s5)
	fff=1;
	if(flag2)
	s2+=x;
	if(s2!=s5)
	fff=1;
	if(n==1)
	{
		fff=0;
		x=213;
	}
	if(fff)
	{
		cout<<-1<<endl;
	}
	else 
	{
		cout<<x<<endl;
	}
	return 0;
}
