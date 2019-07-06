#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
int n = 3000, m = 100000, t = 10;
int re[3005][3005];
int main() {
	freopen("1.in", "w", stdout);
	srand(39392982);
	while (t --) {
	printf("%d %d\n", n, m);
	memset(re,0,sizeof(re));
	for (int i = 1; i <= m; i ++) {
		int x = rand() % n + 1, y = rand() % n + 1;
		while (x == y || re[x][y]) {
			x = rand() % n + 1, y = rand() % n + 1;
		}
		re[x][y] = re[y][x] = 1;
		printf("%d %d\n", x, y);
	}}
	return 0;
}
