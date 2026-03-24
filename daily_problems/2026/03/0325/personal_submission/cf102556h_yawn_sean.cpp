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

	long long m;
	cin >> m;

	if (m == 1) return cout << 1, 0;

	unordered_map<long long, int> cnt;

	for (int x = 2; x < 40'000'000; x ++) {
		while (m % x == 0) {
			cnt[x] ++;
			m /= x;
		}
	}

	if (m > 1) cnt[m] ++;

	int g = 0;
	for (auto &[k, v]: cnt) g = gcd(g, 2 * v);

	for (int i = 1; i <= g; i ++) {
		if (g % i == 0) {
			int factor_cnt = 1;
			for (auto &[k, v]: cnt)
				factor_cnt *= 1 + 2 * v / g * i;
			if (i * factor_cnt == g) {
				long long ans = 1;
				for (auto &[k, v]: cnt) {
					for (int j = 0; j < 2 * v / g * i; j ++) {
						ans *= k;
					}
				}
				return cout << ans, 0;
			}
		}
	}

	cout << -1;

	return 0;
}