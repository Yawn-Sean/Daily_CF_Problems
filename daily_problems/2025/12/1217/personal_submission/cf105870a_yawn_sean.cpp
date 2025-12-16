#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		sort(nums.rbegin(), nums.rend());

		vector<vector<int>> tmp(n);
		map<int, int> mp;

		for (auto &x: nums) {
			tmp[mp[x]].emplace_back(x);
			mp[x] ++;
		}

		reverse(nums.begin(), nums.end());
		for (auto &x: nums) cout << x << ' '; cout << '\n';
		for (auto &y: tmp) for (auto &x: y) cout << x << ' '; cout << '\n';
	}

	return 0;
}