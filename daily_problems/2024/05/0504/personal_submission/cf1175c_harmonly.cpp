#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x = -1, ans = 1e9 + 7;
	for (int i = 0; i < n - k; ++i) {
		int d = a[i + k] - a[i];
		if (d < ans) {
			ans = d;
			x = a[i + k] + a[i] >> 1;
		}
	}
	cout << x << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
