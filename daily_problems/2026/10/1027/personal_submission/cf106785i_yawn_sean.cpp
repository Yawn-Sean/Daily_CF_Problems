#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;
		k --;

		vector<vector<int>> path(n);

		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		auto get_dis = [&] (int u) -> vector<int> {
			vector<int> dis(n, -1);
			queue<int> q; q.push(u);
			dis[u] = 0;

			while (!q.empty()) {
				int u = q.front();
				q.pop();

				for (auto &v: path[u]) {
					if (dis[v] == -1) {
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}

			return dis;
		};

		auto d0 = get_dis(0);

		int rt1 = max_element(d0.begin(), d0.end()) - d0.begin();
		auto d1 = get_dis(rt1);

		int rt2 = max_element(d1.begin(), d1.end()) - d1.begin();
		auto d2 = get_dis(rt2);

		int mx = *max_element(d2.begin(), d2.end());

		cout << (d1[k] == d2[k] && d1[k] + d2[k] == mx ? "Bob" : "Alice") << '\n';
	}

	return 0;
}