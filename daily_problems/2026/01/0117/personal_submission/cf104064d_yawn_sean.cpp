#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int n, inf = 1e9;
	cin >> n;

	int add_ma = -inf, add_mi = inf, minus_ma = -inf, minus_mi = inf;

	while (n --) {
		int x, y;
		cin >> x >> y;
		add_ma = max(add_ma, x + y);
		add_mi = min(add_mi, x + y);
		minus_ma = max(minus_ma, x - y);
		minus_mi = min(minus_mi, x - y);
	}

	if (add_ma == add_mi && minus_ma == minus_mi) cout << 4;
	else if (add_ma == add_mi || minus_ma == minus_mi)
		cout << add_ma - add_mi + minus_ma - minus_mi + 5;
	else cout << add_ma - add_mi + minus_ma - minus_mi + 4;

	return 0;
}