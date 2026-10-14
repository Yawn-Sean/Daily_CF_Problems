#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int f(int x, int y) {return y ? f(y, x / y) : x;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<vector<int>> tmp(n + 1);

	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= n / i; j ++) {
			int g = f(i, j);

			if (i % g == 0) {
				int l = i * j;
				int r = min(i * (j + 1), n + 1);

				for (int v = ((l - 1) / g + 1) * g; v < r; v += g) {
					if (gcd(v, i) == g) {
						tmp[v].emplace_back(i);
					}
				}
			}
		}
	}

	vector<pair<int, int>> res;

	for (int i = 1; i <= n; i ++) {
		for (auto &j: tmp[i]) {
			res.emplace_back(i, j);
		}
	}

	while (q --) {
		long long p;
		cin >> p;

		if (p <= res.size()) cout << res[p - 1].first << ' ' << res[p - 1].second << '\n';
		else cout << "-1 -1\n";
	}

	return 0;
}