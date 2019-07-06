#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 4e5 + 5;
struct node { int y, h; node *next; } *re[maxn], mem[maxn * 2];
inline void add(int x, int y, int h) {
	node *p = &mem[h];
	p -> y = y; p -> h = h; p -> next = re[x]; re[x] = p;
}
int r[maxn], ans[maxn * 4], len;
bool v[maxn * 2], vis[maxn];
void dfs(int x) {
	vis[x] = 1;
	for (node *p = re[x]; p != NULL; p = p -> next) {
		re[x] = p;
		if (!v[p -> h >> 1]) {
			v[p -> h >> 1] = 1;
			dfs(p -> y);
			ans[++ len] = p -> h >> 1;
			if (p -> h % 2) ans[len] *= -1;
		}
	}
}
inline void init(int &x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}
int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	//double t=clock();
	int n, m, x, y;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n + 1; i ++) re[i] = NULL;
		for (int i = 1; i <= n; i ++) r[i] = 0;
		for (int i = 1; i <= m; i ++) {
			init(x); init(y);
			add(x, y, i * 2);
			add(y, x, i * 2 + 1);
			r[x] ++; r[y] ++;
		}
		for (int i = 1; i <= m; i ++) v[i] = 0;
		for (int i = 1, tmp = 0; i <= n; i ++)
			if (r[i] % 2) {
				tmp ++;
				add(n + 1, i, (m + tmp) * 2);
				add(i, n + 1, (m + tmp) * 2 + 1);
				v[m + tmp] = 0;
			}
		len = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = n + 1; i >= 1; i --)
			if (!vis[i]) {
				dfs(i);
				ans[++ len] = m + 1;
			}
		int num = 0;
		for (int i = len; i >= 1; i --) {
			if (abs(ans[i]) > m) continue;
			num ++;
			int j;
			for (j = i - 1; j >= 1; j --)
				if (abs(ans[j]) > m) break;
			i = j + 1;
		}
		printf("%d\n", num);
		for (int i = len; i >= 1; i --) {
			if (abs(ans[i]) > m) continue;
			int j;
			for (j = i - 1; j >= 1; j --)
				if (abs(ans[j]) > m) break;
			printf("%d %d", i - j, ans[i]);
			for (int k = i - 1; k > j; k --)
				printf(" %d", ans[k]);
			printf("\n");
			i = j + 1;
		}
	}
	//cout<<clock()-t<<endl;
	return 0;
}
