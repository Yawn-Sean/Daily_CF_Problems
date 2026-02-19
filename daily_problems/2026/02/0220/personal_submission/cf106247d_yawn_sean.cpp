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

	long long n, k;
	cin >> n >> k;

	long long ans = n + 1;

	for (int i = 1; i <= 1'000'000; i ++) {
		if (n % i == 0) {
			if (i <= k) ans = max(ans, n + i);
			if (n / i <= k) ans = max(ans, n + n / i);
		}
	}

	cout << ans;

	return 0;
}