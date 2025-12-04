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

	int t;
	cin >> t;

	cout << fixed << setprecision(10);

	while (t --) {
		int n, m;
		long long v;
		cin >> n >> m >> v;

		string s;
		cin >> s;

		vector<array<int, 6>> ops(m);
		for (auto &[a, x, b, y, c, z]: ops) {
			cin >> a >> x >> b >> y >> c >> z;
			x --, y --, z --;
		}

		vector<long double> cost(n, -1);
		for (int i = 0; i < n; i ++) {
			if (s[i] == '1') {
				cost[i] = 1;
			}
		}

		for (int _ = 0; _ < n; _ ++) {
			for (auto &[a, x, b, y, c, z]: ops) {
				if (cost[x] >= 0 && cost[y] >= 0) {
					if (cost[z] == -1) cost[z] = (a * cost[x] + b * cost[y]) / c;
					else cost[z] = min(cost[z], (a * cost[x] + b * cost[y]) / c);
				}
			}
		}

		if (cost[0] < 0) cout << 0 << '\n';
		else cout << v / cost[0] << '\n';
	}

	return 0;
}