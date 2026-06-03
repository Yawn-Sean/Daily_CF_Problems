#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x, x --;

	int mod = 998244353;

	vector<int> pw2(n + 1, 1);
	for (int i = 1; i <= n; i ++) pw2[i] = pw2[i - 1] * 2 % mod;

	int ans = 0;
	atcoder::dsu uf(n + 1);

	for (int i = 0; i < n; i ++) {
		uf.init();

		for (int j = 0; j < n; j ++) uf.merge(j, min(nums[j] + i, n));

		int cur = 0;
		for (int j = 0; j < n; j ++) {
			if (uf.leader(j) == j && uf.leader(j) != uf.leader(n)) {
				cur ++;
			}
		}

		ans += pw2[cur] - 1;
		ans %= mod;
	}

	cout << ans;

	return 0;
}