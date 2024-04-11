#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9;
const int M = 20;

int h[N], e[N], ne[N], idx;
int w[N], n, k, T, s, cur;
int fa[N][M], lg[N], d[N], sum[N];
bool flag, success;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void pre(int u, int f, int depth) {
	d[u] = depth;
	fa[u][0] = f;
	for (int i = 1; i <= lg[depth]; i++) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	sum[u] = w[u];
	for (int i = h[u]; i >= 0; i = ne[i]) {
		if (e[i] != f) {
			pre(e[i], u, depth + 1);
			sum[u] ^= sum[e[i]];
		}
	}
}

int lca(int x, int y) {
	if (d[x] < d[y]) {
		return lca(y, x);
	}
	while (d[x] > d[y]) {
		x = fa[x][lg[d[x] - d[y]]];
	}
	if (x == y) {
		return x;
	}
	for (int i = lg[d[x]]; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}

void dfs(int u, int f) {
	if (!flag) {
		for (int i = h[u]; i >= 0; i = ne[i]) {
			if (e[i] != f) {
				dfs(e[i], u);
			}
		}
		if (flag) {
			return;
		}
		if (sum[u] == s) {
			flag = true;
			cur = u;
		}
	} 
}

void solve(int u, int f) {
	if (lca(u, cur) == cur) {
		return;
	}
	if (lca(u, cur) == u) {
		if ((sum[u] ^ s) == s) {
			success = true;
		} else {
			
			for (int i = h[u]; i >= 0; i = ne[i]) {
				if (e[i] != f) {
					solve(e[i], u);
				}
			}
		}
	} else {
		if (sum[u] == s) {
			success = true;
		} else {
			for (int i = h[u]; i >= 0; i = ne[i]) {
				if (e[i] != f) {
					solve(e[i], u);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &T);

	for (int i = 2; i < N; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	while (T--) {
		scanf("%d%d", &n, &k);
		idx = 0;
		for (int i = 0; i <= n; i++) {
			h[i] = -1;
		}
		s = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &w[i]);
			s ^= w[i];
		}
		int u, v;
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		pre(1, 0, 0);
		if (s == 0) {
			puts("YES");
		} else {
			if (k == 2) {
				puts("NO");
				continue;
			}
			flag = false;
			success = false;
			dfs(1, 0);
			solve(1, 0);
			if (success) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}

	return 0;
}