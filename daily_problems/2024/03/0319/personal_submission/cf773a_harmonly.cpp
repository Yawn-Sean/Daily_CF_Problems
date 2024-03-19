#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
	ll x, y, p, q;
	cin >> x >> y >> p >> q;
	auto check = [&](ll t) -> bool {
		return p * t >= x && q * t - p * t >= y - x;
	};
	ll l = 0, r = 1e9;
	if (!check(r)) {
		cout << -1 << '\n';
		return;
	}
	while (l < r) {
		ll mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << l * q - y << '\n';
}

void solve2() {
	ll x, y, p, q;
	cin >> x >> y >> p >> q;
	if (p == 0) {
		cout << (x != 0 ? -1 : 0) << '\n';
		return;
	}
	if (p == q) {
		cout << (x != y ? -1 : 0) << '\n';
		return;
	}
	ll t1 = (x + p - 1) / p;
	ll t2 = ((y - x) + (q - p) - 1) / (q - p);
	cout << q * max(t1, t2) - y << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve2();
	return 0;
}
