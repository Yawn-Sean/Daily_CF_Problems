#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> vals(1 << m, -100), idxs(1 << m, 0), msks(n);

	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < m; j ++) {
			if (s[j] == 'Y') {
				msks[i] |= 1 << j;
			}
		}

		if (vals[msks[i]] < 0) {
			vals[msks[i]] = 0;
			idxs[msks[i]] = i;
		}
	}

	if (vals.back() == 0) {
		int x = idxs.back(), y = -1;
		for (int i = 0; i < n; i ++) {
			if (i != idxs.back() && (y == -1 || __popcount(msks[y]) < __popcount(msks[i]))) {
				y = i;
			}
		}
		if (x > y) swap(x, y);
		cout << x + 1 << ' ' << y + 1;
	}
	else {
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < 1 << m; j ++) {
				if (j >> i & 1) {
					int nj = j ^ (1 << i);
					if (vals[j] + 1 > vals[nj] || (vals[j] + 1 == vals[nj] && idxs[j] < idxs[nj])) {
						vals[nj] = vals[j] + 1;
						idxs[nj] = idxs[j];
					}
				}
			}
		}

		int cur = -1, x = -1, y = -1;

		for (int i = 0; i < n; i ++) {
			int v = (1 << m) - 1 - msks[i];
			if (vals[v] > cur) {
				cur = vals[v];
				x = i;
				y = idxs[v];
			}
		}

		if (cur >= 0) cout << x + 1 << ' ' << y + 1;
		else cout << "No";
	}

	return 0;
}