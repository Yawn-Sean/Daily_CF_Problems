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

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<vector<int>> tmp(n + 1);

		for (int i = 0; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			tmp[y].emplace_back(x);
		}

		long long ans = 0;
		vector<long long> to_add(n + 1, 0);
		priority_queue<int, vector<int>, greater<int>> pq;
		long long cur = 0;

		for (int i = n; i >= 0; i --) {
			for (auto &x: tmp[i]) {
				pq.push(x);
				cur += x;
			}
			while (pq.size() > i + 1) {
				cur -= pq.top();
				pq.pop();
			}

			ans = max(ans, cur);
			to_add[i] = cur - (pq.size() == i + 1 ? pq.top() : 0);
		}

		for (int i = 1; i <= n; i ++)
			to_add[i] = max(to_add[i], to_add[i - 1]);

		while (q --) {
			int x, y;
			cin >> x >> y;
			cout << max(ans, to_add[y] + x) << ' ';
		}
		cout << '\n';
	}

	return 0;
}