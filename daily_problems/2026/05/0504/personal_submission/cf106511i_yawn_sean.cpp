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

	int n;
	cin >> n;

	int block = 20;

	vector<int> ans(n + 1, -1);

	auto update = [&] (vector<int> &v1, vector<int> &v2) -> bool {
		if (v1.empty()) return false;
		cout << "?";
		cout << ' ' << v1.size();
		for (auto &x: v1) cout << ' ' << x;
		cout << ' ' << v2.size();
		for (auto &x: v2) cout << ' ' << x;
		cout << endl;

		int x, y;
		cin >> x >> y;

		if (x < 0) return false;
		ans[x] = y;
		return true;
	};

	for (int i = 1; i <= n; i += block) {
		for (int j = 1; j <= n; j += block) {
			while (true) {
				vector<int> to_query1, to_query2;

				for (int x = i; x < i + block && x <= n; x ++) {
					if (ans[x] == -1) {
						to_query1.emplace_back(x);
					}
				}

				for (int x = j; x < j + block && x <= n; x ++) {
					to_query2.emplace_back(x);
				}

				if (!update(to_query1, to_query2)) break;
			}
		}
	}

	cout << "!";
	for (int i = 1; i <= n; i ++) cout << ' ' << ans[i];

	return 0;
}