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

	int t;
	cin >> t;

	auto f = [&] (int x1, int x2) -> int {
		int x = abs(x1 - x2);
		if (!x) return 0;
		return (x - 1) % 2 + 1;
	};

	while (t --) {
		int n, m, r1, c1, r2, c2;
		cin >> n >> m >> r1 >> c1 >> r2 >> c2;
		cout << f(r1, r2) + f(c1, c2) << '\n';
	}

	return 0;
}