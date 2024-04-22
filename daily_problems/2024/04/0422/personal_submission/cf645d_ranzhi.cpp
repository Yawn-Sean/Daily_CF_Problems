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
#define endl '\n'

int n, m;

bool can_acquire(vector<PII>& arr, int& t) {
	vector<vector<int>> g(n + 1);
	vector<int> indeg(n + 1);
	for (int i = 0; i < t; i++) {
		int u = arr[i].first, v = arr[i].second;
		g[u].emplace_back(v);
		indeg[v] += 1;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indeg[i]) q.emplace(i);
	}
	vector<int> ans;
	while (q.size()) {
		if (q.size() != 1) return false;
		auto t = q.front(); q.pop();
		ans.emplace_back(t);
		for (auto&& node : g[t]) {
			indeg[node] -= 1;
			if (!indeg[node]) q.emplace(node);
		}
	}
	if (ans.size() != n) return false;
	return true;
}

void solve() {
	cin >> n >> m;
	vector<PII> arr;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		arr.push_back({ u, v });
	}
	int left = 1, right = m, mid;
	while (left <= right) {
		mid = left + right >> 1;
		if (can_acquire(arr, mid)) right = mid - 1;
		else left = mid + 1;
	}
	if (left == m + 1) left = -1;
	cout << left << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while (t--) solve();
	return 0;
}
