#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;

const int N = 510, M = N * N;
int h[N], e[M], ne[M], w[M], ind;
int val[N];
bool vis[N];
ld ans = 0;

void add(int a, int b, int c) {
	e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
	return;
}

void bfs(int root) {
	queue<int> q;
	q.emplace(root);
	while (q.size()) {
		auto t = q.front(); q.pop();
		vis[t] = true;
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (vis[j]) continue;
			ans = max(ans, (ld)(val[t] + val[j]) / w[i]);
			q.emplace(j);
		}
	}
	return;
}

int main() {
	memset(h, -1, sizeof h);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i <= m; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		bfs(i);
	}
	printf("%.15Lf\n", ans);
	return 0;
}
