#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=5005;
int n,k;
string s[maxn];
int cnt1[30],cnt2[30],ham[maxn];

int main(){
	cin>>k>>n;
	for (int i=0;i<k;i++) cin>>s[i];
	for (int i=0;i<n;i++) cnt1[s[0][i]-'a']++;
	bool ok=0;
	for (int i=0;i<26;i++) if (cnt1[i]>1) ok=1;
	for (int j=1;j<k;j++){
		memset(cnt2,0,sizeof(cnt2));
		for (int i=0;i<n;i++) cnt2[s[j][i]-'a']++;
		for (int i=0;i<26;i++) if (cnt1[i]!=cnt2[i]){
			puts("-1");
			return 0;
		}
		for (int i=0;i<n;i++) ham[j]+=(s[0][i]!=s[j][i]);
	}
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++){
			int sum=0;
			for (int t=1;t<k;t++){
				int cnt=ham[t];
				cnt-=(s[0][i]!=s[t][i]);
				cnt-=(s[0][j]!=s[t][j]);
				cnt+=(s[0][j]!=s[t][i]);
				cnt+=(s[0][i]!=s[t][j]);
				if ((cnt==0 && ok) || cnt==2) sum++;
				else break;
			}
			if (sum==k-1){
				swap(s[0][i],s[0][j]);
				cout<<s[0];
				return 0;
			}
		}
	puts("-1");
	return 0;
}
