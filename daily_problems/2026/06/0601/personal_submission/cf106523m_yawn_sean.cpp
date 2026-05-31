#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> ds(n);
	for (auto &x: ds) cin >> x;

	vector<long double> ps(n);
	for (auto &x: ps) cin >> x;

	long double l = 0, r = 1e9;

	for (int i = 0; i < 100; i ++) {
		long double mid = (l + r) / 2, cur = mid;

		for (int j = n - 1; j >= 0; j --) {
			cur = ps[j] * min(cur + 1, (long double)ds[j]) + (1 - ps[j]) * (cur + 1);
		}

		if (cur < mid) r = mid;
		else l = mid;
	}

	cout << fixed << setprecision(15) << (l + r) / 2;

	return 0;
}