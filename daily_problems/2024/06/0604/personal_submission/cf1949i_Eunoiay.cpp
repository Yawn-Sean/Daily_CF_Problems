#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n), y(n), r(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> r[i];
	}

	vector<vector<int>> adj(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			i64 dx = x[i] - x[j];
			i64 dy = y[i] - y[j];
			i64 dis = r[i] + r[j];
			if (dx * dx + dy * dy == dis * dis) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> clr(n, -1);
	bool flg = false;

	for (int i = 0; i < n; ++i) {
		if (~clr[i]) {
			continue;
		}
		clr[i] = 0;

		stack<int> stk;
		int c[2] = {};

		c[0] = 1;
		stk.push(i);

		bool f = true;
		while (!stk.empty()) {
			auto u = stk.top();
			stk.pop();

			for (auto v : adj[u]) {
				if (clr[v] == -1) {
					clr[v] = clr[u] ^ 1;
					c[clr[v]] += 1;
					stk.push(v);
				} else if (clr[u] == clr[v]) {
					f = false;
				}
			}
		}
		if (f && c[0] != c[1]) {
			flg = true;
			break;
		}
	}

	cout << (flg ? "YES" : "NO") << "\n";

	return 0;
}
