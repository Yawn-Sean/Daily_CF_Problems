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
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		cout << "YES\n1\n";

		vector<pair<int, int>> ops;
		vector<int> used(n, 0);

		for (int i = n - 1; i >= 1; i --) {
			vector<int> vis(i, -1);
			for (int j = 0; j < n; j ++) {
				if (!used[j]) {
					int x = nums[j] % i;
					if (vis[x] != -1) {
						ops.emplace_back(vis[x], j);
						used[j] = 1;
						break;
					}
					vis[x] = j;
				}
			}
		}

		reverse(ops.begin(), ops.end());

		for (auto &[x, y]: ops) cout << x + 1 << ' ' << y + 1 << '\n';
	}

	return 0;
}