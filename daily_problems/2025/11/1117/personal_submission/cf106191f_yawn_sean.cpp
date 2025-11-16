#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

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

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	long long cur = 0;
	int neg = 0;
	map<long long, vector<int>> mp;

	mp[cur].emplace_back(0);
	for (int i = 0; i < n; i ++) {
		cur += nums[i];
		if (nums[i] < 0) neg ++;
		else neg --;
		mp[cur].emplace_back(neg);
	}

	map<long long, atcoder::fenwick_tree<int>> fens;

	for (auto &[k, v]: mp) {
		fens[k] = atcoder::fenwick_tree<int>(v.size());
		sort(v.begin(), v.end());
	}

	cur = 0;
	neg = 0;

	long long ans = 0;

	fens[cur].add(lower_bound(mp[cur].begin(), mp[cur].end(), neg) - mp[cur].begin(), 1);
	for (int i = 0; i < n; i ++) {
		cur += nums[i];
		if (nums[i] < 0) neg ++;
		else neg --;
		int p = lower_bound(mp[cur].begin(), mp[cur].end(), neg) - mp[cur].begin();
		ans += fens[cur].sum(0, p + 1);
		fens[cur].add(p, 1);
	}

	cout << ans;

	return 0;
}