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

	auto f = [&] (long long x) -> long long {
		long long start = 1;
		int d = 1;
		long long ans = 0;

		for (int i = 0; i < 18; i ++) {
			if (start > x) break;
			ans += min(start * 9, x - start + 1) * d;
			start *= 10;
			d ++;
		}

		return ans;
	};

	long long n, k, l, r;
	cin >> n >> k;

	l = 1, r = 1e17;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (f(mid + n - 1) - f(mid - 1) < k) l = mid + 1;
		else r = mid - 1;
	}

	if (f(l + n - 1) - f(l - 1) == k) cout << l;
	else cout << -1;

	return 0;
}