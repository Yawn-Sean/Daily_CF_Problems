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

	int n, k;
	cin >> n >> k;

	vector<long long> nums(n);
	for (auto &v: nums) cin >> v;

	for (int i = 0; i < n; i ++) nums.emplace_back(nums[i]);

	for (int i = 0; i < 2 * n; i ++)
		nums[i] -= 1ll * i * k;

	vector<int> stk;
	vector<int> ans(n);
	for (int i = 2 * n - 1; i >= 0; i --) {
		while (!stk.empty() && nums[stk.back()] >= nums[i])
			stk.pop_back();
		if (i < n) ans[i] = stk.back() % n + 1;
		stk.emplace_back(i);
	}

	for (auto &x: ans) cout << x << ' ';

	return 0;
}