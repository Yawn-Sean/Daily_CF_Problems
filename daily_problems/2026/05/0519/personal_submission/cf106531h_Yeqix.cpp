#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> in(n + 1);
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		in[v]++;
	}

	vector<set<int>> st(n + 1);
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int j, x;
		cin >> j >> x;
		st[x].insert(j);
	}

	queue<array<int, 2>> que;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			que.push({i, 1});
		}
	}

	int mx = 0;
	while (!que.empty()) {
		auto [u, cnt] = que.front();
		que.pop();
		mx = max(mx, cnt);
		if (st[u].count(cnt)) {
			cnt++;
			que.push({u, cnt});
			continue;
		}

		for (const auto& v : edge[u]) {
			if (--in[v] == 0) {
				que.push({v, cnt + 1});
			}
		}
	}

	if (count(in.begin() + 1, in.end(), 0) == n) {
		cout << mx;
	} else {
		cout << -1;
	}
	return 0;
}
