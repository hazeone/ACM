#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char a[maxn];
int b[maxn], len;
bool cmp(int a, int b) { return a > b; }
inline int work(int m) {
	int p, tmp = 0;
	for (p = 1; p <= len && m > 1; p ++) {
		tmp += b[p];
		m -= 2;
	}
	if (p <= len && m > 0) tmp += b[p];
	return tmp;
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		scanf("%s", a + 1);
		int s, e;
		for (s = 1; s <= n; s ++) if (a[s] == '0') break;
		for (e = n; e >= 1; e --) if (a[e] == '0') break;
		if (s > e) {
			printf("%d\n", n);
			continue;
		}
		len = 0;
		for (int i = s; i <= e; i ++) {
			if (a[i] == '0') continue;
			b[++ len] = 1; int j;
			for (j = i + 1; j <= e; j ++)
				if (a[j] == '0') break;
				else b[len] ++;
			i = j;
		}
		sort(b + 1, b + 1 + len, cmp);
		int ans = max(work(m), s - 1), tmp;
		if (s > 1 && m >= 1) {
			tmp = work(m - 1) + s - 1;
			ans = max(ans, tmp);
		}
		if (e < n && m >= 1) {
			tmp = work(m - 1) + n - e;
			ans = max(ans, tmp);
		}
		if (s > 1 && e < n && m >= 2) {
			tmp = work(m - 2) + s - 1 + n - e;
			ans = max(ans, tmp);
		}
		if (s > 1 && e < n && m >= 1)
			ans = max(ans, s - 1 + n - e);
		printf("%d\n", ans);
	}
	return 0;
}
