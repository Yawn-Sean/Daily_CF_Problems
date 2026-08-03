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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> v1(n), v2(n);
		for (auto &x: v1) cin >> x;
		for (auto &x: v2) cin >> x;

		vector<int> cnt(n, 0);
		for (auto &x: v1) if (x <= n) cnt[x - 1] ++;

		int to_fill = 0;
		long long total = 0;
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < n; i ++) {
			if (cnt[i]) {
				to_fill += cnt[i] - 1;
				total += v2[i];
				pq.push(v2[i]);
			}
			else if (to_fill) {
				to_fill --;
				total += v2[i];
				pq.push(v2[i]);
			}
			else if (!pq.empty() && pq.top() < v2[i]) {
				total += v2[i] - pq.top();
				pq.pop(), pq.push(v2[i]);
			}
		}

		cout << total << '\n';
	}

	return 0;
}