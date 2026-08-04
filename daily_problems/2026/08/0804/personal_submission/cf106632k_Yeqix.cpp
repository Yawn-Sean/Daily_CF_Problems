#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<i64> d(n + 1), p(n + 1);
	for (int i = 1; i < n; i++) {
		d[i] = a[i] ^ a[i + 1];
		p[i + 1] = p[i] + d[i];
	}

	i64 ans = 0;
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		while (l <= i && p[i] - p[l] - (a[i] ^ a[l]) > k) {
			l++;
		}
		while (r <= i && p[i] - p[r] - (a[i] ^ a[r]) >= k) {
			r++;
		}
		ans += r - l;
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