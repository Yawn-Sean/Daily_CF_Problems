#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> u(m), v(m), w(m);
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
		g[u[i]].push_back(i);
		g[v[i]].push_back(i);
	}
	
	vector<i64> dis(n, 1e18);
	dis[0] = 0;
	
	vector<int> from(n, -1);
	priority_queue<pair<i64,int>, vector<pair<i64,int>>, greater<pair<i64,int>> > pq;
	pq.push({0, 0});
	
	while (!pq.empty()) {
		auto [d, x] = pq.top();
		pq.pop();
		if (d > dis[x]) continue;
		for (auto& i: g[x]) {
			int y = (u[i] ^ v[i] ^ x);
			if (dis[y] > dis[x] + w[i]) {
				dis[y] = dis[x] + w[i];
				from[y] = i;
				pq.push({dis[y], y});
			}	
		}
	}
	
	vector<int> st_range(n - 1);
	iota(st_range.begin(), st_range.end(), 1);
	sort(st_range.begin(), st_range.end(), [&](int i, int j) {
		return dis[i] < dis[j];
	});
	
	int ans = min(k, n - 1);
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << from[st_range[i]] + 1 << ' ';
	}
	return 0;
}
