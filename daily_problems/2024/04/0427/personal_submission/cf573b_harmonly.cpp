#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a[0] = a.back() = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		a[i] = min(a[i], a[i - 1] + 1);
	}
	for (int i = n - 2; i >= 0; --i) {
		a[i] = min(a[i], a[i + 1] + 1);
		ans = max(ans, a[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while (t--) solve();
	return 0;
}
