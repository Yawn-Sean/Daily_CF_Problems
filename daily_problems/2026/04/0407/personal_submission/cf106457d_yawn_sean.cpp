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

	auto query = [&] (int i, int j) -> int {
		cout << "? " << i << ' ' << j << endl;
		char c;
		cin >> c;
		if (c == 'X') return 0;
		if (c == 'P') return 1;
		return 2;
	};

	int n, t, b;
	cin >> n >> t >> b;

	vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
	int l = t, r = t;

	for (int i = 1; i <= n; i ++) {
		ans[1][i] = query(1, i);
		ans[n][i] = query(n, i);

		if (ans[1][i]) {
			l = min(l, i);
			r = max(r, i);
		}
	}

	for (int i = 2; i < n; i ++) {
		ans[i][l] = query(i, l);

		if (ans[i][l]) {
			while (l > 1) {
				l --;
				ans[i][l] = query(i, l);
				if (!ans[i][l]) {
					l ++;
					break;
				}
			}
		}
		else {
			while (l < n) {
				l ++;
				ans[i][l] = query(i, l);
				if (ans[i][l]) break;
			}
		}

		ans[i][r] = query(i, r);

		if (ans[i][r]) {
			while (r < n) {
				r ++;
				ans[i][r] = query(i, r);
				if (!ans[i][r]) {
					r --;
					break;
				}
			}
		}
		else {
			while (r > 1) {
				r --;
				ans[i][r] = query(i, r);
				if (ans[i][r]) break;
			}
		}

		for (int j = l + 1; j < r; j ++) ans[i][j] = 2;
	}

	int area = 0;
	for (auto &x: ans) for (auto &y: x) area += y;

	cout << "! " << area - 2;

	return 0;
}