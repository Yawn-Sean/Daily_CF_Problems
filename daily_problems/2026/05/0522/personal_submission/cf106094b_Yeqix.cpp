#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n, t;
	cin >> n >> t;
	vector<array<i64, 2>> d(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> d[i][0];
		d[i][1] = i;
	}

	sort(d.begin() + 1, d.end());

	vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + d[i][0];
	}

	i64 ans = 0;
	array<int, 2> chose = { -1, -1};
	for (int i = 0; i <= n; i++) {
		if (pre[i] + (pre[n] - pre[i]) / 2 > t) {
			continue;
		}
		int l = i, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pre[i] + (pre[mid] - pre[i]) * 2 / 3 + (pre[n] - pre[mid]) / 2 <= t) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		i64 res = i * 100LL + (r - i) * 75LL + (n - r) * 50LL;
		if (res > ans) {
			ans = res;
			chose = {i, r};
		}
	}

	cout << ans << "\n";
	vector<double> idx(n + 1);
	auto [l, r] = chose;
	for (int i = 1; i <= l; i++) {
		idx[d[i][1]] = 1;
	}
	for (int i = l + 1; i <= r; i++) {
		idx[d[i][1]] = 1.5;
	}
	for (int i = r + 1; i <= n; i++) {
		idx[d[i][1]] = 2;
	}

	for (int i = 1; i <= n; i++) {
		cout << idx[i] << " ";
	}
	cout << "\n";
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