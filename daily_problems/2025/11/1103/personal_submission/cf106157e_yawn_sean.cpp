#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	cout << fixed << setprecision(10);
	double pi = acos(-1);

	while (t --) {
		int x, y;
		cin >> x >> y;

		if (y <= 3 * x) cout << 0 << '\n';
		else {
			auto area = [&] (int cnt) -> double {
				double side = (1.0 * y / cnt - x) / 2;
				return side * side / tan(pi / cnt) * cnt;
			};

			int l = 3, r = y / x;
			while (l < r) {
				int mid = (l + r) / 2;
				if (area(mid) < area(mid + 1)) l = mid + 1;
				else r = mid;
			}

			cout << area(l) << '\n';
		}
	}

	return 0;
}