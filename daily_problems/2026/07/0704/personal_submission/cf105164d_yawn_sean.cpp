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

	long long total = 1ll * n * (n - 1) * (n - 2) / 6;

	for (int z = 1; z < n - 1; z ++) {
		int xy_bound = min(z, n - z);
		total -= 3ll * (xy_bound - 1) * xy_bound / 2;
	}

	long long c1 = n / 3, c2 = 0;
	
	for (int z = 1; z <= n; z ++) {
		int l = z / 2 + 1, r = (n - z) / 2;
		c2 += max(r - l + 1, 0);
	}

	c2 -= c1;
	total -= c1 + 3 * c2;

	cout << (total / 6 + c1 + c2) % 1'000'000'007;

	return 0;
}