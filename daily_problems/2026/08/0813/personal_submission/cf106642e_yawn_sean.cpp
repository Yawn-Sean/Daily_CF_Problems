#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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
	for (auto &x: nums) cin >> x;

	if (*max_element(nums.begin(), nums.end()) != 2) cout << "NO\n";
	else if (*min_element(nums.begin(), nums.end()) != 0) cout << "NO\n";
	else {
		vector<int> tmp;
		for (auto &x: nums) if (x != 1) tmp.emplace_back(x);

		bool flg = true;
		for (int i = 1; i < tmp.size(); i ++) {
			if (tmp[i - 1] == tmp[i]) {
				flg = false;
			}
		}

		cout << (flg && tmp.size() % 2 == 0 ? "YES\n" : "NO\n");
	}

	return 0;
}