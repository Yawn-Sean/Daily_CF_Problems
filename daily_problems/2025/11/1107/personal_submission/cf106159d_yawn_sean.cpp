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

vector<int> prep(vector<int>& nums) {
	int n = nums.size();
	vector<int> pi(n, 0);
	int j = 0;

	for (int i = 1; i < n; i ++) {
		while (j && nums[i] != nums[j])
			j = pi[j - 1];
		if (nums[i] == nums[j]) j ++;
		pi[i] = j;
	}

	return pi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e4, n, m;
	cin >> n >> m;

	vector<int> nums1(n), nums2(m);
	for (auto &x: nums1) cin >> x;
	for (auto &x: nums2) cin >> x;

	vector<int> vals;

	for (int i = 1; i < m; i ++)
		vals.emplace_back((nums2[i] - nums2[i - 1] + M) % M);
	
	vals.emplace_back(-1);

	for (int i = 1; i < n; i ++)
		vals.emplace_back((nums1[i] - nums1[i - 1] + M) % M);
	
	auto kmp = prep(vals);

	vector<int> cnt(M, 0);
	
	for (int i = m; i < n + m - 1; i ++) {
		if (kmp[i] == m - 1) {
			cnt[(nums2[0] - nums1[i - 2 * (m - 1)] + M) % M] ++;
		}
	}

	auto ma_ele = max_element(cnt.begin(), cnt.end());

	cout << ma_ele - cnt.begin() << ' ' << *ma_ele;

	return 0;
}