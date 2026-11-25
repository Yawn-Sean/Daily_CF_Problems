#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

#include "atcoder/modint.hpp"
using mint = atcoder::modint1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n, k, q;
		cin >> n >> k >> q;

		vector<vector<tuple<int, long long, int>>> updates(n + 1);

		for (int i = 0; i < q; i ++) {
			long long d;
			int l, r, c;
			cin >> d >> l >> r >> c;
			updates[l - 1].push_back({1, d, c});
			updates[r].push_back({-1, d, c});
		}

		mint ans = 0;

		vector<vector<int>> trie(2, vector<int>(q * k + 5, -1));
		vector<int> sz(q * k + 5);
		vector<mint> dp(q * k + 5);

		int pt = 1;

		for (int i = 0; i < n; i ++) {
			for (auto &[op, d, c]: updates[i]) {
				int cur = 0;
				vector<int> stk;

				for (int bit = k - 1; bit >= 0; bit --) {
					stk.emplace_back(cur);
					int w = d >> bit & 1;
					if (trie[w][cur] == -1) trie[w][cur] = pt ++;
					cur = trie[w][cur];
					sz[cur] += op;
				}

				dp[cur] += c * op;

				reverse(stk.begin(), stk.end());

				for (auto &idx: stk) {
					int v0 = trie[0][idx];
					int v1 = trie[1][idx];

					bool f0 = v0 >= 0 && sz[v0] > 0;
					bool f1 = v1 >= 0 && sz[v1] > 0;

					if (f0) {
						if (f1) dp[idx] = dp[v0] + dp[v1];
						else dp[idx] = 2 * dp[v0];
					}
					else {
						if (f1) dp[idx] = 2 * dp[v1];
						else dp[idx] = 0;
					}
				}
			}

			ans += dp[0];
		}

		cout << ans.val() << '\n';
	}

	return 0;
}