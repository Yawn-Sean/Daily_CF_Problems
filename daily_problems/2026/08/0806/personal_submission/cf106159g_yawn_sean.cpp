#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#include "atcoder/dsu"

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

	vector<vector<int>> path(n);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		x --;
		path[i].emplace_back(x);
		path[x].emplace_back(i);
	}

	long long ans = 0;
	int cur = 0;

	atcoder::dsu uf(n);
	vector<int> vis(n, 0), order(n);

	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] > nums[j];});

	for (auto &i: order) {
		vis[i] = 1;
		cur ++;

		for (auto &j: path[i]) {
			if (vis[j]) {
				if (uf.leader(i) != uf.leader(j)) {
					cur -= (uf.size(i) + 1) / 2;
					cur -= (uf.size(j) + 1) / 2;
					uf.merge(i, j);
					cur += (uf.size(i) + 1) / 2;
				}
				else cur -= uf.size(i) % 2;
			}
		}

		ans = max(ans, 1ll * cur * nums[i]);
	}

	cout << ans;

	return 0;
}