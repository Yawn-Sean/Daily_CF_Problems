#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n, m, k;
	cin >> n >> m >> k;
	vector<i64> a(n + 1);
	vector<vector<i64>> pre(n + 1, vector<i64>(m));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			pre[i][j] = pre[i - 1][j] + (a[i] >> j & 1);
		}
	}

	auto get = [&](int l, int r)->int {
		i64 cnt = 0;
		for (int j = 0; j < m; j++) {
			i64 v = pre[r][j] - pre[l - 1][j];
			cnt += (v > 0 && v < r - l + 1);
		}
		return cnt;
	};

	i64 ans = 0;
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		if (get(1, i) < k) {
			continue;
		}

		while (l <= i && get(l, i) >= k) {
			l++;
		}
		while (r <= i && get(r, i) > k) {
			r++;
		}

		ans += l - r;
	}

	cout << ans << "\n";
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