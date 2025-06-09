#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2e5 + 10, M = N << 1, INF = 0x3f3f3f3f;

int n, t;
int head[N], ed[M], ne[M], idx;
int d1[N], d2[N];

void add(int u, int v) {
	ed[idx] = v, ne[idx] = head[u], head[u] = idx++;
}

void dfs(int u, int fa, int d[]) {
	for (int i = head[u]; ~i; i = ne[i]) {
		int v = ed[i];
		if (v == fa) continue;
		d[v] = d[u] + 1;
		dfs(v, u, d);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	memset(head, -1, sizeof head);
	cin >> n >> t;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}

	dfs(1, -1, d1);
	dfs(t, -1, d2);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (d1[i] > d2[i]) ans = max(ans, d1[i] * 2);
	}

	cout << ans << "\n";
	return 0;
}
