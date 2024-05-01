#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;

inline int red() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = red(), m = red(), i;
	vector<int> path;
	vector<bool> a(n), b(n);
	vector<vector<int>> g(n);
	while (m--) {
		int x = red(), y = red();
		x--, y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	function<bool(int, int)> Dfs = [&](int u, int p) -> bool {
		if (a[u]) {
			return false;
		}
		a[u] = true;
		path.emplace_back(u);
		if (b[u] && p != u) {
			return true;
		}

		for (int x : g[u]) {
			if (Dfs(x, p)) {
				return true;
			}
		}
		path.pop_back();
		return false;
	};

	int idx = -1;
	for (i = 0; i < n; i++) {
		if (g[i].size() >= 4) {
			a.assign(n, false);
			b.assign(n, false);
			a[i] = true;
			path.clear();
			for (int x : g[i]) {
				b[x] = true;
			}
			for (int x : g[i]) {
				if (Dfs(x, x)) {
					idx = i;
					break;
				}
			}
		}
	}
	if (idx == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		int l = path.size();
		cout << l + 3 << '\n';
		cout << idx + 1 << ' ' << path[0] + 1 << '\n';
		cout << idx + 1 << ' ' << path[l - 1] + 1 << '\n';
		for (i = 0; i < l - 1; i++) {
			cout << path[i] + 1 << ' ' << path[i + 1] + 1 << '\n';
		}
		int cnt = 0;
		for (int x : g[idx]) {
			if (cnt == 2) {
				break;
			}
			if (b[x] && x != path[0] && x != path[l - 1]) {
				++cnt;
				cout << idx + 1 << ' ' << x + 1 << '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = red();
	while (t--) {
		solve();
	}

	return 0;
}