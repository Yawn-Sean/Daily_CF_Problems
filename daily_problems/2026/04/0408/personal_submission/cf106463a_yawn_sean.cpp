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
		int n, k, x, y;
		cin >> n >> k >> x >> y;

		vector<int> nums(k);
		for (auto &v: nums) cin >> v;

		for (int i = 1; i < k; i ++)
			nums[i] += nums[i - 1], nums[i] %= n;

		vector<int> vis(n, -1), target(k, 0);

		for (int i = k - 1; i >= 0; i --) {
			int to_find_pos = (nums[i] + x - y + n) % n;
			target[i] = (vis[to_find_pos] != -1 ? target[vis[to_find_pos]] : (y + nums.back() - nums[i] + n) % n);
			vis[nums[i]] = i;
		}

		for (int i = 0; i < n; i ++) {
			if (i != x) {
				int to_find_pos = (x - i + n) % n;
				cout << (vis[to_find_pos] != -1 ? target[vis[to_find_pos]] : (i + nums.back()) % n) << ' ';
			}
		}

		cout << '\n';
	}

	return 0;
}