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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> p(n + 1);
		for (int i = 1; i <= n; i ++) cin >> p[i];

		long long ans = 0;
		vector<int> vis(n + 1, 0);
		vector<long long> tmp;

		for (int i = 1; i <= n; i ++) {
			if (!vis[i]) {
				vector<int> cur = {i};
				while (p[cur.back()] != i) cur.emplace_back(p[cur.back()]);

				for (auto &x: cur) vis[x] = 1;

				int l = cur.size();

				if (l % 2 == 0) {
					long long v = 0;
					for (int j = 0; j < l; j ++) {
						if (j & 1) v += cur[j];
						else v -= cur[j];
					}
					ans += abs(v);
				}
				else {
					long long v = 0;
					for (int j = 1; j < l; j ++) {
						if (j & 1) v += cur[j];
						else v -= cur[j];
					}

					long long res = 0;
					for (int j = 0; j < l; j ++) {
						if (j & 1) {
							res = max(res, cur[j] + v);
							v += cur[(j + 1) % l];
							v -= cur[j];
						}
						else {
							res = max(res, cur[j] - v);
							v -= cur[(j + 1) % l];
							v += cur[j];
						}
					}

					tmp.emplace_back(res);
				}
			}
		}

		sort(tmp.rbegin(), tmp.rend());

		for (int i = 0; i < tmp.size(); i ++) {
			if (i % 2 == 0) ans += tmp[i];
			else ans -= tmp[i];
		}

		cout << ans << '\n';
	}

	return 0;
}