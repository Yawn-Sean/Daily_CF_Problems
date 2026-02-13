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

	vector<vector<int>> tmp = {
		{2, 1, 1, 0},
		{2, 0, 2, 0},
		{1, 1, 2, 1}
	};
	int inf = 1e9;

	int t;
	cin >> t;

	while (t --) {
		vector<int> nums(4);
		for (auto &x: nums) cin >> x;

		unsigned int ans = inf;
		for (int i = 0; i < 16; i ++) {
			unsigned int cur = 0;
			for (int j = 0; j < 4; j ++) {
				if (i >> j & 1)  {
					cur += nums[j];
				}
			}

			int to_check = inf;
			for (int j = 0; j < 3; j ++) {
				int val = 0;
				for (int k = 0; k < 4; k ++) {
					if (i >> k & 1) {
						val += tmp[j][k];
					}
				}
				to_check = min(to_check, val);
			}

			if (to_check) ans = min(ans, cur / to_check);
		}

		cout << ans << '\n';
	}

	return 0;
}