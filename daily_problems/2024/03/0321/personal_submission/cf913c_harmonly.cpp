#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll inf = 1e18;

void solve() {
	int n, L; cin >> n >> L;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i < n; ++i) {
		c[i] = min(c[i], c[i - 1] << 1);
	}
	ll ans = inf, sum = 0;
	for (int i = n - 1; i >= 0; --i) {
		ll t = L / (1 << i);
		sum += t * c[i];
		L -= t << i;
		ans = min(ans, sum + (L > 0) * c[i]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
