#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	i64 ans = 0;
	map<i64, i64> mp1, mp2;
	map<array<i64, 2>, i64> cnt;
	for (int i = 1; i <= n; i++) {
		i64 n1 = a[i] - b[i], n2 = a[i] + b[i];
		ans += mp1[n1] + mp2[n2];
		mp1[n1]++, mp2[n2]++;
		cnt[ {a[i], b[i]}]++;
	}

	for (const auto& [l, r] : cnt) {
		ans -= r * (r - 1) / 2;
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