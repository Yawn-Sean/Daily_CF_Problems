#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	i64 n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << 1 << "\n";
		return;
	} else if (n == 2) {
		if (m & 1) {
			cout << "2 1\n";
		} else {
			cout << "1 2\n";
		}
		return;
	}

	m = min(m, n);

	for (int i = n; i >= n - m + 1; i--) {
		cout << i << " ";
	}
	for (int i = 1; i <= n - m; i++) {
		cout << i << " ";
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
