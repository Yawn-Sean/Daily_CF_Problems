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

	auto dis = [&] (long long x1, long long y1, long long x2, long long y2) -> long long {
		return abs(x1 - x2) + abs(y1 - y2);
	};

	long long ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	long long ans = dis(ax, ay, bx, by);

	int t;
	cin >> t;

	while (t --) {
		int k;
		long long b;
		cin >> b >> k;

		for (auto x1: {ax, (ay - b) * k}) {
			for (auto x2: {bx, (by - b) * k}) {
				long long y1 = k * x1 + b;
				long long y2 = k * x2 + b;

				ans = min(ans, dis(ax, ay, x1, y1) + abs(x1 - x2) + dis(x2, y2, bx, by));
			}
		}
	}

	cout << ans;

	return 0;
}