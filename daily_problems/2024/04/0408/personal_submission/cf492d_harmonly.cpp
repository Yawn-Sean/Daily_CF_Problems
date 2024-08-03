#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i) {
		ll a; cin >> a;
		ll l = 1, r = 1e15;
		while (l < r) {
			ll m = (l + r) / 2;
			if (m / x + m / y >= a) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << (l % x != 0 ? "Vanya" : (l % y != 0 ? "Vova" : "Both")) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while (t--) solve();
	return 0;
}
