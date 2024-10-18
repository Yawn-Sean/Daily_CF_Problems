#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	vector<int> vis1(2e5), vis2(2e5);
	while (t--) {
		int n, m, k, q;
		cin >> n >> m >> k >> q;
		
		vector<int> xs(q), ys(q);
		for (int i = 0; i < q; i++) {
			cin >> xs[i] >> ys[i];
			xs[i]--; ys[i]--;
		}
		
		int c1 = 0, c2 = 0;
		i64 ans = 1;
		for (int i = q - 1; i >= 0; i--) {
			if ((not vis1[xs[i]] and c2 < m) or (not vis2[ys[i]] and c1 < n)) {
				ans = (ans * 1ll * k) % mod;
				if (not vis1[xs[i]]) {
					vis1[xs[i]] = 1;
					++c1;
				}
				if (not vis2[ys[i]]) {
					vis2[ys[i]] = 1;
					++c2;
				}
			}
		}
		
		for (auto& x: xs) { vis1[x] = 0; }
		for (auto& y: ys) { vis2[y] = 0; }
		cout << ans << '\n';
	}

	return 0;
}
