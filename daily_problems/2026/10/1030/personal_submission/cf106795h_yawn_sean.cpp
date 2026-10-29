#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> nodes(k);
	for (auto &x: nodes) cin >> x, x --;

	vector<vector<int>> path(n);
	
	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> dis(n, -1);
	dis[0] = 0;

	vector<int> que = {0};
	for (int i = 0; i < que.size(); i ++) {
		int u = que[i];
		for (auto &v: path[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				que.emplace_back(v);
			}
		}
	}

	vector<bitset<8000>> bs(n);

	for (int i = 0; i < k; i ++)
		bs[nodes[i]].set(i, 1);

	reverse(que.begin(), que.end());
	for (auto &u: que) {
		for (auto &v: path[u]) {
			if (dis[v] == dis[u] + 1) {
				bs[u] |= bs[v];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (bs[i].count() == k) {
			ans = max(ans, dis[i]);
		}
	}

	cout << ans;

	return 0;
}