#include <bits/stdc++.h>
using namespace std;
int f[1005][1005];
int dfs(int x, int y) {
	if (x == 0 && y == 0) return false;
	if (f[x][y] != -1) return f[x][y];
	int mi = min(x, y), res = 0;
	for (int i = 1; i <= mi; i ++)
		res = res | !dfs(x - i, y - i);
	for (int i = 1; i <= x; i ++)
		res = res | !dfs(x - i, y);
	for (int i = 1; i <= y; i ++)
		res = res | !dfs(x, y - i);
	return f[x][y] = res;
}
int main() {
	for (int i = 0; i <= 1000; i ++)
		for (int j = 0; j <= 1000; j ++)
			f[i][j] = -1;
	for (int i = 1; i <= 500; i ++)
		for (int j = i; j <= 500; j ++)
			if(dfs(i,j)==0)printf("%d %d %d\n", i, j, dfs(i, j));
	return 0;
}
