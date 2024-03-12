#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<double> x(n), v(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	auto check = [&](double t) -> bool {
		double l = 0, r = 1e9;
		for (int i = 0; i < n; ++i) {
			l = max(l, x[i] - v[i] * t);
			r = min(r, x[i] + v[i] * t);
		}
		return l <= r;
	};
	double l = 0, r = 1e9;
	while (r - l > 1e-6) {
		double mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << fixed << setprecision(6) << l << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
