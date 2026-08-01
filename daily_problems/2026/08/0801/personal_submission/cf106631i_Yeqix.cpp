#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	vector<int> dist(n + 1, inf);
	vector<int> vis(n + 1);
	queue<int> que;
	que.push(b);
	dist[b] = 0, vis[b] = 2;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (const auto& v : edge[u]) {
			vis[v]++;
			if (vis[v] == 2) {
				dist[v] = dist[u] + 1;
				que.push(v);
			}
		}
	}

	if (dist[a] == inf) {
		cout << "-1\n";
	} else {
		cout << dist[a] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}