#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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
		int n, k;
		cin >> n >> k;

		vector<pair<int, long long>> vals(n);
		for (auto &[a, b]: vals) cin >> a >> b;

		sort(vals.begin(), vals.end(), [&] (pair<int, long long> &x, pair<int, long long> &y) {return x.second < y.second;});

		long long cur = 0, ans = -1e18;
		priority_queue<int, vector<int>, greater<int>> pq;

		for (auto &[x, y]: vals) {
			if (pq.size() == k - 1) {
				ans = max(ans, cur + x - y);
			}

			cur += x;
			pq.push(x);

			if (pq.size() == k) {
				cur -= pq.top();
				pq.pop();
			}
		}

		cout << ans << '\n';
	}

	return 0;
}