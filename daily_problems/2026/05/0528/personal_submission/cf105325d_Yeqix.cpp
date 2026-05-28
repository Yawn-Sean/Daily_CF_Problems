#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n;
	cin >> n;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	auto b = a;

	i64 ans = 0;
	i64 r = n;
	for (int i = 1; i <= n; i++) {
		while (r > 0 && a[r] < i) {
			r--;
		}
		ans += min(r, b[i]);
	}

	cout << accumulate(a.begin(), a.end(), 0LL) - ans << "\n";
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