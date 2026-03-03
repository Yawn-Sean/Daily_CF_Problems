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

	vector<int> nums(52);
	for (auto &v: nums) cin >> v;

	for (int i = 0; i < 8; i ++) {
		vector<int> nnums;
		for (int i = 0; i < 26; i ++) {
			nnums.emplace_back(nums[i]);
			nnums.emplace_back(nums[i + 26]);
		}
		nums.swap(nnums);

		bool flg = true;
		for (int i = 26; i < 52; i ++) {
			if (nums[i] == 1) {
				flg = false;
			}
		}

		if (flg) return cout << "YES", 0;
	}

	cout << "NO";

	return 0;
}