#include <bits/stdc++.h>
using namespace std;
long long S[20];
inline long long lowbit(long long x) { return x & (-x); }
long long work(long long x) {
	if (x == 0) return 0;
	int k = 62;
	for (; k >= 0; k --)
		if (1LL << k & x) break;
	return work(x - (1LL << k)) + S[k] + (1LL << k);
}
int main() {
	S[1] = 1;
	for (int i = 2; i <= 62; i ++)
		S[i] = S[i - 1] * 2 + (1LL << i - 1);
	printf("S : ");
	for (int i = 1; i <= 5; i ++) printf("%lld ", S[i]);
	printf("\n");
	int m, op;
	long long n, x, y;
	while (scanf("%lld%d", &n, &m) != EOF) {
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &op);
			if (op == 1) {
				scanf("%lld %lld", &x, &y);
				printf("%lld\n", work(y) - work(x - 1));
			} else {
				int ans = 0;
				scanf("%lld", &x);
				for (long long j = x; j <= n; j += lowbit(j)) ans ++;
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
