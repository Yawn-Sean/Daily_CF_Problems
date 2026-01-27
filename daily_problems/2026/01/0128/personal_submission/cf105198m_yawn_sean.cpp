#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		long long sx, sy, tx, ty, k;
		cin >> sx >> sy >> tx >> ty >> k;

		long long dx = abs(sx - tx), dy = abs(sy - ty);
		if (dx < dy) swap(dx, dy);

		if (dx <= (dy + 1) * k) cout << dx + dy << '\n';
		else cout << dx + dy + (dx - (dy + 1) * k + 2 * k - 1) / (2 * k) * 2 << '\n';
	}

	return 0;
}