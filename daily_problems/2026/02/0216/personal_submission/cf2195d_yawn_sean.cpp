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
		
		vector<long long> nums(n);
		for (auto &v: nums) cin >> v;

		long long total = (nums[0] + nums[n - 1]) / (n - 1);
		int cur = 0;

		for (int i = 0; i < n - 1; i ++) {
			int x = -(nums[i] - nums[i + 1] - total) / 2 - cur;
			cur += x;
			cout << x << ' ';
		}

		cout << total - cur << '\n';
	}

	return 0;
}