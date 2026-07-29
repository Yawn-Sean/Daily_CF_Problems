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

	int t, inf = 1e9;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		vector<vector<long long>> cur(n);
		vector<int> pts(n, 0);

		for (int i = 0; i < n; i ++) {
			priority_queue<pair<long long, int>> pq;
	
			for (int j = 0; j < i; j ++)
				pq.push({cur[j][0] + gcd(nums[j], nums[i]), j});
			
			for (int j = 0; j < k; j ++) {
				if (!pq.empty()) {
					auto [x, y] = pq.top(); pq.pop();
					cur[i].emplace_back(x);
					pts[y] ++;

					if (pts[y] < cur[y].size())
						pq.push({cur[y][pts[y]] + gcd(nums[y], nums[i]), y});
				}
			}

			if (cur[i].size() < k) cur[i].emplace_back(0);

			for (int j = 0; j < i; j ++) pts[j] = 0;
		}

		{
			priority_queue<long long, vector<long long>, greater<long long>> pq;
			for (auto &x: cur) {
				for (auto &y: x) {
					pq.push(y);
					if (pq.size() > k) pq.pop();
				}
			}

			if (pq.size() < k) cout << 0 << '\n';
			else cout << pq.top() << '\n';
		}
	}

	return 0;
}