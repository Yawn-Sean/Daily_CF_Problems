#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> strs(n);
	for (auto &s: strs) cin >> s;

	string pattern;
	cin >> pattern;

	int k = pattern.size();

	vector<vector<int>> transition(k + 1, vector<int>(26, 0));

	for (int i = 0; i <= k; i ++) {
		for (int j = 0; j < 26; j ++) {
			string tmp = pattern.substr(0, i);
			tmp += (char)('a' + j);

			int l = tmp.size();
			for (int cur_len = min(l, k); cur_len >= 0; cur_len --) {
				bool flg = true;

				for (int idx = 0; idx < cur_len; idx ++) {
					if (pattern[idx] != tmp[l - cur_len + idx]) {
						flg = false;
					}
				}

				if (flg) {
					transition[i][j] = cur_len;
					break;
				}
			}
		}
	}

	vector<vector<pair<int, int>>> transition_string(n, vector<pair<int, int>>(k + 1));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= k; j ++) {
			int cur = j, cnt = 0;

			for (auto &c: strs[i]) {
				cur = transition[cur][c - 'a'];
				if (cur == k) cnt ++;
			}

			transition_string[i][j] = {cur, cnt};
		}
	}

	auto f = [&] (int x, int y) -> int {return x * (k + 1) + y;};

	vector<vector<int>> dp((k + 1) * (k + 1), vector<int>(1 << n, -1));

	for (int i = 0; i <= k; i ++) dp[f(i, i)][0] = 0;

	for (int msk = 0; msk < (1 << n); msk ++) {
		for (int i = 0; i <= k; i ++) {
			for (int j = 0; j <= k; j ++) {
				if (dp[f(i, j)][msk] != -1) {
					for (int bit = 0; bit < n; bit ++) {
						if (msk >> bit & 1) continue;
						int nmsk = msk | (1 << bit);
						auto [nj, ncnt] = transition_string[bit][j];
						dp[f(i, nj)][nmsk] = max(dp[f(i, nj)][nmsk], dp[f(i, j)][msk] + ncnt);
					}
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i ++) {
		int l = strs[i].size();

		for (int j = 0; j < l; j ++) {
			int cur = 0, cnt = 0;

			for (int idx = j; idx < l; idx ++) {
				cur = transition[cur][strs[i][idx] - 'a'];
				if (cur == k) cnt ++;
			}

			int msk = (1 << n) - 1 - (1 << i);

			for (int ncur = 0; ncur <= k; ncur ++) {
				if (dp[f(cur, ncur)][msk] != -1) {
					int vcur = ncur, vcnt = cnt + dp[f(cur, ncur)][msk];

					for (int idx = 0; idx < j; idx ++) {
						vcur = transition[vcur][strs[i][idx] - 'a'];
						if (vcur == k) vcnt ++;
					}

					ans = max(ans, vcnt);
				}
			}
		}
	}

	cout << ans;

	return 0;
}