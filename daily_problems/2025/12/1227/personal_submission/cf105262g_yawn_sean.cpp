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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n), tmp(2 * n + 1, -1);
		for (int i = 0; i < n; i ++) {
			cin >> nums[i];
			tmp[2 * i + 1] = nums[i];
		}

		vector<int> wing(2 * n + 1, 0);
		int idx = 0;

		for (int i = 0; i <= 2 * n; i ++) {
			if (idx + wing[idx] >= i)
				wing[i] = min(wing[2 * idx - i], idx + wing[idx] - i);
			while (i > wing[i] && i + wing[i] < 2 * n && tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1])
				wing[i] ++;
			if (wing[i] + i > wing[idx] + idx) idx = i;
		}

		vector<int> diff_k(n + 1, 0), diff_b(n + 1, 0);

		auto add = [&] (int &x, int y) -> void {
			x += y;
			if (x >= mod) x -= mod;
		};

		auto minus = [&] (int &x, int y) -> void {
			x -= y;
			if (x < 0) x += mod;
		};

		for (int i = 0; i <= 2 * n; i ++) {
			int l = (i - wing[i]) / 2, r = (i + wing[i]) / 2;
			int mid = (l + r + 1) / 2;

			add(diff_k[l], 1);
			minus(diff_k[mid], 1);
			minus(diff_b[l], (l - 1 + mod) % mod);
			add(diff_b[mid], (l - 1 + mod) % mod);

			minus(diff_k[mid], 1);
			add(diff_k[r], 1);
			add(diff_b[mid], r);
			minus(diff_b[r], r);
		}

		for (int i = 0; i < n; i ++) {
			add(diff_k[i + 1], diff_k[i]);
			add(diff_b[i + 1], diff_b[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; i ++)
			add(ans, (1ll * diff_k[i] * i + diff_b[i]) % mod * nums[i] % mod);
		
		cout << ans << '\n';
	}

	return 0;
}