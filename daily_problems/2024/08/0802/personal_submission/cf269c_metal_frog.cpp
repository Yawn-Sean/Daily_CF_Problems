#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> edg(m);
	vector<vector<pii>> G(n);
	vector<int> inbound(n), outbound(n), weight(m), rev(m), vis(m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		weight[i] = w;
		edg[i] = {u, v};
		G[u].emplace_back(v, i);
		G[v].emplace_back(u, i);
		outbound[u] += w;
		outbound[v] += w;
	}
	queue<int> que;
	for (auto [v, i] : G[0]) {
		int w = weight[i];
		inbound[v] += w;
		outbound[v] -= w;
		pii tmp = {0, v};
		if (edg[i] != tmp) rev[i] = 1; 
		vis[i] = 1;
		if (inbound[v] == outbound[v]) que.push(v);
	}
	for (auto [v, i] : G[n - 1]) {
		int w = weight[i];
		inbound[n - 1] += w;
		pii tmp = {v, n - 1};
		if (edg[i] != tmp) rev[i] = 1;
		vis[i] = 1;
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto [v, i] : G[u]) if (!vis[i]) {
			int w = weight[i];
			inbound[v] += w;
			outbound[v] -= w;
			pii tmp = {u, v};
			if (edg[i] != tmp) rev[i] = 1;
			vis[i] = 1;
			if (inbound[v] == outbound[v]) que.push(v);
		}
	}
	for (int i = 0; i < m; i++) {
		cout << rev[i] << endl;
	}
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
