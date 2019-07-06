#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
LL dp[N][2];
int c[N],n;
string a[N],b[N];
int main()
{
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
  scanf("%d",&c[i]);
  for(int i=1;i<=n;++i)
  {
     cin>>a[i];b[i]=a[i];
     reverse(b[i].begin(),b[i].end());
  }
  memset(dp,-1,sizeof(dp));
  dp[1][1]=c[1];dp[1][0]=0;
  for(int i=2;i<=n;++i)
  {
    if(a[i]>=a[i-1]&&dp[i-1][0]!=-1)
    dp[i][0]=dp[i-1][0];
    if(a[i]>=b[i-1]&&dp[i-1][1]!=-1)
    {
      if(dp[i][0]==-1)dp[i][0]=dp[i-1][1];
      else dp[i][0]=min(dp[i][0],dp[i-1][1]);
    }
    if(b[i]>=a[i-1]&&dp[i-1][0]!=-1)
    dp[i][1]=dp[i-1][0]+c[i];
    if(b[i]>=b[i-1]&&dp[i-1][1]!=-1)
    {
      if(dp[i][1]==-1)dp[i][1]=dp[i-1][1]+c[i];
      else dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
    }
    if(dp[i][0]==-1&&dp[i][1]==-1)
    {
      printf("-1\n");return 0;
    }
  }
  int i=n;
  if(dp[i][0]!=-1&&dp[i][1]==-1)
  printf("%I64d\n",dp[i][0]);
  else if(dp[i][1]!=-1&&dp[i][0]==-1)
  printf("%I64d\n",dp[i][1]);
  else printf("%I64d\n",min(dp[i][0],dp[i][1]));
  return 0;
}
