#include<bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 1;
const int flen = 92;
unsigned long long f[flen + 1];
int n, m, s[maxn];

int find(int k)
{
	if(k <= 0) return 1;
	for(int i = 1; i < flen; i++)
		if((f[i] <= k) && (f[i + 1] >= k))
			if(k - f[i] <= f[i + 1] - k) return f[i]; else return f[i + 1];
}

int main()
{
	freopen("C.in", "r", stdin);
	ios::sync_with_stdio(false);
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= flen; i++) f[i] = f[i - 1] + f[i - 2];
	while(cin >> n >> m)
	{
		memset(s, 0, sizeof(s));
		for(int i = 0; i < m; i++)
		{
			int cas, a, b;
			cin >> cas >> a >> b;
			if(cas == 1) s[a] += b;
			if(cas == 2)
			{
				int ans = 0;
				for(int j = a; j <= b; j++) ans += s[j];
				cout << ans << endl;
			}
			if(cas == 3)
				for(int j = a; j <= b; j++) s[j] = find(s[j]);
		}
	}
}
