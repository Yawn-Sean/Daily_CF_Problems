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

	int t;
	cin >> t;

	while (t --) {
		int n, p, x;
		cin >> n >> p >> x;

		x = p - x;

		vector<int> cnt(n + 1, 0);
		for (int i = 0; i < p; i ++) {
			int v;
			cin >> v;
			cnt[n - v] ++;
		}

		vector<int> nums;
		for (int i = 0; i <= n; i ++) {
			while (cnt[i] --) {
				nums.emplace_back(i);
			}
		}

		long long cur = 0, ans = n;
		for (int i = 0; i < p; i ++) {
			cur += nums[i];
			if (x - (p - i - 1) > 0) {
				ans = min(ans, cur / (x - (p - i - 1)));
			}
		}

		cout << n - ans << '\n';
	}

	return 0;
}