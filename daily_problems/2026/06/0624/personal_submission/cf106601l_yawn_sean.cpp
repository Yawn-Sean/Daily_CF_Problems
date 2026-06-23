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

	long long n;
	cin >> n;

	int ans = 0;

	for (int i = 2; i <= 1'000'000; i ++) {
		int xor_val = 0, cnt = 0;
		long long cur = n;

		while (cur) {
			xor_val ^= cur % i;
			cnt ++;
			cur /= i;
		}

		if (cnt <= 2) break;
		if (xor_val == 0) ans ++;
	}

	for (int i = 1; i <= 1'000'000; i ++) {
		if (1ll * i * (i + 2) > n) break;
		if (n % i == 0) ans ++;
	}

	cout << ans;

	return 0;
}