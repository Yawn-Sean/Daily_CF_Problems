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

	int n;
	cin >> n;

	vector<int> nums1(n), nums2(n);
	for (auto &v: nums1) cin >> v;
	for (auto &v: nums2) cin >> v;

	vector<int> vals;

	for (int i = 0; i < n; i ++) {
		if (nums1[i] > nums2[i]) {
			vals.emplace_back(nums1[i]);
			vals.emplace_back(nums2[i]);
		}
		else {
			vals.emplace_back(nums2[i]);
			vals.emplace_back(nums1[i]);
		}
	}

	vector<int> cur;

	for (auto &x: vals) {
		int pt = lower_bound(cur.begin(), cur.end(), x) - cur.begin();
		if (pt == cur.size()) cur.emplace_back(x);
		else cur[pt] = x;
	}

	cout << cur.size();

	return 0;
}