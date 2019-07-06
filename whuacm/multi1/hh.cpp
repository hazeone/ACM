#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 105, mod = 1e9 + 7;
LL quick(LL a,LL b)
{
	LL res = a, ans = 1;
	for (int i = 0; i < 30; i ++)
	{
		if (1 << i & b) ans = ans * res % mod;
		res = res * res % mod;
	}
	return ans;
}
int l[maxn], r[maxn];
LL ans;
int cal(int x, int y)
{
	return (x + y) * (y - x + 1) / 2;
}
int dc(int mx, int x, int y)
{
	if (x > y) return 0;
	return cal(mx - y + 1, mx - x + 1);
}
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d", &n);
		int mx = 0, mi = 0;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d%d", &l[i], &r[i]);
			mx = max(mx, r[i]);
			mi = max(mi, l[i]);
		}
		ans = 0;
		for (int i = mi; i <= mx; i ++)
		{
			LL t1 = 1, t2 = 1;
			for (int j = 1; j <= n; j ++)
			{
				t1 = t1 * dc(i, l[j], min(i, r[j])) % mod;
				if (r[j] >= i) t2 = t2 * dc(i, l[j], i - 1) % mod;
				else t2 = t2 * dc(i, l[j], r[j]) % mod;
			}
			ans = (ans + t1 - t2 + mod) % mod;
		}
		LL tmp = 1;
		for (int i = 1; i <= n; i ++)
			tmp = tmp * (r[i] - l[i] + 1) % mod;
		printf("%I64d\n", ans * quick(tmp, mod - 2) % mod);
	}
	return 0;
}
