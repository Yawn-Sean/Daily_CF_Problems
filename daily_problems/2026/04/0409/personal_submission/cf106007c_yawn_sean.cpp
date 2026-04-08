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
		int n, m;
		cin >> n >> m;

		vector<int> acc(n + 1), vis = {0};

		for (int i = 1; i <= n; i ++) {
			cin >> acc[i];
			for (int j = 0; j < acc[i]; j ++)
				vis.emplace_back(i);
			acc[i] += acc[i - 1];
		}

		for (int d = 1; d <= m; d ++) {
			int pt = 0;
			bool flg = true;

			while (pt < n) {
				int pos = vis[min(acc[n], acc[pt] + m - d + 1)];
				if (m < acc[pos] - acc[pt]) {
					flg = false;
					break;
				}
				pt = pos;
			}

			if (flg) {
				cout << d << '\n';
				break;
			}
		}
	}

	return 0;
}