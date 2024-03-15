#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
const ll inf = 1e18;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll dp1 = -inf, dp2 = -inf;
	ll ans = -inf;
	for (int i = 1; i < n; ++i) {
		ll t = dp1;
		dp1 = max(dp2, 0ll) + abs(a[i - 1] - a[i]);
		dp2 = max(t, 0ll) - abs(a[i - 1] - a[i]);
		ans = max(ans, dp1);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
