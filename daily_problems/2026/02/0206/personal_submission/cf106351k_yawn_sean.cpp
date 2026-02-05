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

	int M = 1e5;
	vector<vector<int>> factors(M + 1);

	for (int i = 1; i <= M; i ++) {
		for (int j = i; j <= M; j += i) {
			factors[j].emplace_back(i);
		}
	}

	int n, x, y;
	cin >> n >> x >> y;

	vector<int> cnt(M + 1, 0);
	while (n --) {
		int x;
		cin >> x;
		cnt[x] ++;
	}

	long long ans = 0;

	for (int i = x; i <= y; i ++) {
		ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		for (int j = 0; j < factors[i].size(); j ++) {
			for (int k = 0; k < j; k ++) {
				int g = gcd(factors[i][j], factors[i][k]);
				if (g >= x && 1ll * factors[i][j] * factors[i][k] / g == i) {
					ans += 1ll * cnt[factors[i][j]] * cnt[factors[i][k]];
				}
			}
		}
	}

	cout << ans;

	return 0;
}