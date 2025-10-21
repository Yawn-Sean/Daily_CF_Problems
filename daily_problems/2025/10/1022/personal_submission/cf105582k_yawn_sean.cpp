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

	int n;
	cin >> n;

	vector<pair<int, int>> pts;

	if (n & 1) {
		pts.emplace_back(0, 0);

		int x = 0, y = 0;

		for (int i = 0; i < n / 2 - 1; i ++) {
			y += 25;
			pts.emplace_back(x, y);
			x += 25;
			pts.emplace_back(x, y);
		}

		x = max(x, 25);
		pts.emplace_back(x, 0);
		pts.emplace_back(x / 25 * 9, -x / 25 * 12);
	}
	else {
		pts.emplace_back(0, 0);

		int x = 0, y = 0;

		for (int i = 0; i < n / 2 - 1; i ++) {
			y += 25;
			pts.emplace_back(x, y);
			x += 25;
			pts.emplace_back(x, y);
		}

		pts.emplace_back(x, 0);		
	}

	int dx = 5, dy = 12;

	for (auto &[x, y]: pts)
		cout << x * dx + y * dy << ' ' << x * (-dy) + y * dx << '\n';

	return 0;
}