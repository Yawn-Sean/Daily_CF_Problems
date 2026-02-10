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

	int n;
	cin >> n;

	if (n % 4 == 3) cout << -1;
	else {
		vector<int> nums(n);
		iota(nums.begin(), nums.end(), 1);

		for (int i = 3; i < n; i += 4)
			swap(nums[i - 1], nums[i]);

		for (auto &x: nums) cout << x << ' ';
	}

	return 0;
}