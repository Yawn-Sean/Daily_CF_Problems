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

	vector<int> nums(n * 2);
	for (auto &x: nums) cin >> x;

	int special = 0;
	vector<int> vis(n + 1, 0), stk;

	for (auto &x: nums) {
		if (!stk.empty() && stk.back() == x) {
			vis[x] = 0;
			stk.pop_back();
		}
		else {
			if (vis[x]) {
				special = x;
				break;
			}

			vis[x] = 1;
			stk.emplace_back(x);
		}
	}

	if (!special) {
		cout << n << '\n';
		for (int i = 1; i <= n; i ++) cout << i << " \n"[i == n];
	}
	else {
		int l = -1, r = -1;
		for (int i = 0; i < 2 * n; i ++) {
			if (nums[i] == special) {
				if (l == -1) l = i;
				r = i;
			}
		}

		fill(vis.begin(), vis.end(), 0);

		for (int i = l + 1; i <= r - 1; i ++) vis[nums[i]] ^= 1;

		auto check = [&] (int x) -> bool {
			vector<int> cur;
			for (auto &v: nums) {
				if (v != x) {
					if (!cur.empty() && cur.back() == v) cur.pop_back();
					else cur.emplace_back(v);
				}
			}
			return cur.empty();
		};

		vector<int> ans;
		if (check(special)) ans.emplace_back(special);

		for (int i = 0; i <= n; i ++) {
			if (vis[i]) {
				if (check(i)) ans.emplace_back(i);
				break;
			}
		}

		sort(ans.begin(), ans.end());

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i ++)
			cout << ans[i] << " \n"[i + 1 == ans.size()];
	}

	return 0;
}