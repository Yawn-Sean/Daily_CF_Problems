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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> nums(n);
		int total_or = 0;
		for (auto &x: nums) cin >> x, total_or |= x;

		int op_must = 0, ans = 0, cur = -1;
		for (int i = 0; i < n; i ++) {
			if (nums[i] != total_or) {
				op_must |= total_or ^ nums[i];
				if (i > cur) {
					ans ++;
					cur = i + m - 1;
				}
			}
		}

		int q;
		cin >> q;

		while (q --) {
			int x;
			cin >> x;

			if ((x & op_must) != op_must) cout << -1 << '\n';
			else if ((x & total_or) == x || ans == 0) cout << ans << '\n';
			else cout << (n - 1) / m + 1 << '\n';
		}
	}

	return 0;
}