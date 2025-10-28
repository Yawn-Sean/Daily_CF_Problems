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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;
	vector<int> to_compare = nums;
	sort(to_compare.begin(), to_compare.end());

	map<int, int> mp;

	for (auto &v: nums) {
		mp[v] ^= 1;
		mp[((k - 1ll * v * v) % m + m) % m] ^= 1;
	}

	int total = 0;
	for (auto &[x, v]: mp) total += v;

	if (total > 2) return cout << "NO", 0;

	bool flg;

	for (auto &[x, v]: mp) {
		if (v) {
			vector<int> ans = {x};
			for (int i = 0; i < n - 1; i ++) {
				int v = ans.back();
				ans.emplace_back(((k - 1ll * v * v) % m + m) % m);
			}
			vector<int> compare_ans = ans;
			sort(compare_ans.begin(), compare_ans.end());

			flg = true;
			for (int i = 0; i < n; i ++) {
				if (to_compare[i] != compare_ans[i]) {
					flg = false;
				}
			}
			if (flg) {
				reverse(ans.begin(), ans.end());
				cout << "YES\n";
				for (auto &x: ans) cout << x << ' ';
				return 0;
			}
		}
	}

	vector<int> ans = {nums[0]};
	for (int i = 0; i < n - 1; i ++) {
		int v = ans.back();
		ans.emplace_back(((k - 1ll * v * v) % m + m) % m);
	}
	vector<int> compare_ans = ans;
	sort(compare_ans.begin(), compare_ans.end());

	flg = true;
	for (int i = 0; i < n; i ++) {
		if (to_compare[i] != compare_ans[i]) {
			flg = false;
		}
	}

	if (flg) {
		reverse(ans.begin(), ans.end());
		cout << "YES\n";
		for (auto &x: ans) cout << x << ' ';
		return 0;
	}
	else cout << "NO";

	return 0;
}