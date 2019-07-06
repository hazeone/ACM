#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int fa[maxn], siz[maxn], a[maxn], b[maxn], n, m, X, Y;
bool v[maxn];
int getfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
inline void work(int x, int y) {
	if (x == y) return ;
	if (siz[x] > siz[y]) {
		siz[x] += siz[y];
		fa[y] = x;
	} else {
		siz[y] += siz[x];
		fa[x] = y;
	}
}
inline void merge(int x, int y) {
	int gx = getfa(x), gy = getfa(y);
	int gxx = getfa(x + n), gyy = getfa(y + n);
	work(gx, gyy); work(gxx, gy);
}
inline bool check() {
	for (int i = 1; i <= n; i ++)
		if (getfa(i) == getfa(i + n)) return false;
	for (int i = 1; i <= n; i ++)
		if (!v[i]) return false;
	return true;
}
int main() {
	int x, y;
	while (scanf("%d%d%d%d", &n, &m, &X, &Y) != EOF) {
		for (int i = 1; i <= n * 2; i ++) fa[i] = i, siz[i] = 1, v[i] = 0;
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d", &x, &y);
			merge(x, y);
			v[x] = 1;
			v[y] = 1;
		}
		for (int i = 1; i <= X; i ++) scanf("%d", &a[i]), v[a[i]] = 1;
		for (int i = 1; i <= Y; i ++) scanf("%d", &b[i]), v[b[i]] = 1;
		for (int i = 1; i <= X; i ++)
			for (int j = 1; j <= Y; j ++)
				merge(a[i], b[j]);
		if (check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
