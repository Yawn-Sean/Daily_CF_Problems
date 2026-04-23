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

	int n, q;
	cin >> n >> q;

	vector<int> is_prime(n + 1, 1), primes;

	for (int i = 2; i <= n; i ++) {
		if (is_prime[i]) {
			primes.emplace_back(i);
			for (int j = i * 2; j <= n; j += i) {
				is_prime[j] = 0;
			}
		}
	}

	vector<int> ans = {1};
	vector<pair<int, int>> stk;
	stk.emplace_back(1, 0);

	while (!stk.empty()) {
		auto [x, idx] = stk.back(); stk.pop_back();
		if (idx == primes.size() || x * primes[idx] > n) continue;

		stk.emplace_back(x, idx + 1);

		while (1ll * x * primes[idx] <= n) {
			x *= primes[idx];
			ans.emplace_back(x);
			stk.emplace_back(x, idx + 1);
		}
	}

	while (q --) {
		int idx; cin >> idx;
		cout << ans[idx - 1] << '\n';
	}

	return 0;
}