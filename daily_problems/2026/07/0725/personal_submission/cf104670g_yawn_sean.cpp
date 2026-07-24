#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<array<int, 3>> circles(n);
	for (auto &[x, y, r]: circles) cin >> x >> y >> r;

	auto start = chrono::steady_clock::now();

	int freq = 0, total = 0;

	auto random_value = [&] () -> long double {
		auto val = rngl();
		long double ret = (long double)val / (1ull << 63) / 2;
		return ret;
	};

	while (true) {
		auto now = chrono::steady_clock::now();
		if (chrono::duration<double>(now - start).count() >= 2.5) break;

		double x = random_value() * 30 - 10;
		double y = random_value() * 30 - 10;
		total++;

		for (auto &[vx, vy, r]: circles) {
			if ((x - vx) * (x - vx) + (y - vy) * (y - vy) <= r * r) {
				freq ++; 
				break;
			}
		}
	}

	cout << fixed << setprecision(15) << (long double)freq / total * 900;

	return 0;
}