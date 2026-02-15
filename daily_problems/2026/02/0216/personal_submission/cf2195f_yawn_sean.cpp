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

		vector<array<int, 3>> funcs(n);
		for (auto &[a, b, c]: funcs) cin >> a >> b >> c;
		
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&] (int i, int j) {
			return funcs[i][2] < funcs[j][2];
		});

		vector<int> dp_pref(n, 1), dp_suff(n, 1);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				int vi = order[i], vj = order[j];

				if (funcs[vi][0] == funcs[vj][0]) {
					if (funcs[vi][1] == funcs[vj][1])
						dp_pref[vi] = max(dp_pref[vi], dp_pref[vj] + 1);
				}
				else {
					int a = funcs[vi][0] - funcs[vj][0];
					int b = funcs[vi][1] - funcs[vj][1];
					int c = funcs[vi][2] - funcs[vj][2];

					if (1ll * b * b < 4ll * a * c)
						dp_pref[vi] = max(dp_pref[vi], dp_pref[vj] + 1);
				}
			}
		}

		for (int i = n - 1; i >= 0; i --) {
			for (int j = i + 1; j < n; j ++) {
				int vi = order[i], vj = order[j];

				if (funcs[vi][0] == funcs[vj][0]) {
					if (funcs[vi][1] == funcs[vj][1])
						dp_suff[vi] = max(dp_suff[vi], dp_suff[vj] + 1);
				}
				else {
					int a = funcs[vi][0] - funcs[vj][0];
					int b = funcs[vi][1] - funcs[vj][1];
					int c = funcs[vi][2] - funcs[vj][2];

					if (1ll * b * b < 4ll * a * c)
						dp_suff[vi] = max(dp_suff[vi], dp_suff[vj] + 1);
				}
			}
		}

		for (int i = 0; i < n; i ++) cout << dp_pref[i] + dp_suff[i] - 1 << ' ';
		cout << '\n';
	}

	return 0;
}