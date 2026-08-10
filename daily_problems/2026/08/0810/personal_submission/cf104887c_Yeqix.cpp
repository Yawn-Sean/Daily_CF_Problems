#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 r, c, m, k;
	cin >> r >> c >> m >> k;

	if (k > min(r, c) || m < k || m > max({r, c}) * min({r, c, k})) {
		cout << "NO\n";
		return;
	}

	vector<string> ans(r, string(c, '.'));
	for (int i = 0; i < min({r, c, k}) && m; i++) {
		ans[i][i] = '#', m--;
	}

	int nr = (r > c ? r : min({r, c, k})), nc = (r > c ? min({r, c, k}): c);
	for (int i = 0; i < nr && m; i++) {
		for (int j = 0; j < nc && m; j++) {
			if (ans[i][j] == '.') {
				ans[i][j] = '#', m--;
			}
		}
	}

	cout << "YES\n";
	for (const auto& x : ans) {
		cout << x << "\n";
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