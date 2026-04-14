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
		int n;
		cin >> n;

		vector<pair<int, int>> monsters;

		for (int i = 0; i < n; i ++) {
			int p, s;
			cin >> p >> s;

			if (!s) monsters.emplace_back(2 * p, p);
			else monsters.emplace_back(p, 2 * p);
		}

		vector<int> x1, x2;

		for (int i = 0; i < n; i ++) {
			int p, s;
			cin >> p >> s;

			if (!s) x1.emplace_back(p);
			else x2.emplace_back(p);
		}

		sort(x1.begin(), x1.end());

		bool flg = true;
		priority_queue<int, vector<int>, greater<int>> pq;

		sort(monsters.begin(), monsters.end(), [&] (pair<int, int> &x, pair<int, int> &y) {return x.first > y.first;});

		for (auto &[x, y]: monsters) {
			while (!x1.empty() && x1.back() > x) {
				if (pq.empty()) {
					flg = false;
					break;
				}
				x1.pop_back();
				pq.pop();
			}
			pq.push(y);
		}

		while (!x1.empty()) {
			x1.pop_back();
			pq.pop();
		}

		if (!flg) cout << "NO\n";
		else {
			sort(x2.begin(), x2.end());

			for (auto &x: x2) {
				if (pq.top() < x) flg = false;
				pq.pop();
			}

			cout << (flg ? "YES" : "NO") << '\n';
		}
	}

	return 0;
}