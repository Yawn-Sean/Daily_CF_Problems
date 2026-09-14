#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<string> grid(n);
		for (auto &s: grid) cin >> s;

		vector<int> pos_h(n, -1), pos_v(n, -1);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (grid[i][j] == 'H') pos_h[i] = j;
				else pos_v[j] = i;
			}
		}

		cout << n << '\n';
		if (*min_element(pos_h.begin(), pos_h.end()) == -1) {
			for (int i = 0; i < n; i ++) {
				cout << pos_v[i] + 1 << ' ' << i + 1 << '\n';
			}
		}
		else {
			for (int i = 0; i < n; i ++) {
				cout << i + 1 << ' ' << pos_h[i] + 1 << '\n';
			}
		}
	}

	return 0;
}