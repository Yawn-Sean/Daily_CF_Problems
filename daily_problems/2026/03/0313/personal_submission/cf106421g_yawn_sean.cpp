#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long reversePairs(vector<long long> &nums) {
	vector<long long> vals = nums;
	sort(vals.begin(), vals.end());

	int n = nums.size();
	atcoder::fenwick_tree<int> fen(n);

	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		int p = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
		ans += fen.sum(p + 1, n);
		fen.add(p, 1);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	long long ans = 0;

	vector<long long> acc(n + 1, 0);

	for (int i = 0; i < n; i ++) acc[i + 1] = acc[i] + 1ll * nums[i] * n - (1ll * b * n + 1);
	ans += reversePairs(acc);

	for (int i = 0; i < n; i ++) acc[i + 1] = acc[i] + 1ll * nums[i] * n - 1ll * a * n;
	ans -= reversePairs(acc);

	cout << ans;

	return 0;
}