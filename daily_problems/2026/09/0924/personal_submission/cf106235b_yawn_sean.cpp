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

	int n;
	cin >> n;

	long long total_method = 1;
	for (int i = 1; i <= n; i ++) total_method *= i;

	vector<int> path(n, 0);
	vector<long long> dp(1 << n, 0);
	dp[0] = 1;

	auto count_method = [&] () -> long long {
		for (int i = 1; i < (1 << n); i ++) {
			dp[i] = 0;
			int cur = i;

			while (cur) {
				int bit = __builtin_ctz(cur);
				if ((path[bit] & i) == 0) dp[i] += dp[i - (1 << bit)];
				cur -= cur & -cur;
			}
		}
		return dp.back();
	};

	while (true) {
		char c;
		cin >> c;

		if (c == '?') {
			int x, y;
			cin >> x >> y;
			x --, y --;

			int orig = path[x];
			path[x] |= 1 << y;
			long long w1 = count_method();
			path[x] = orig;

			long long w2 = total_method - w1;

			if (w1 >= w2) {
				path[x] |= 1 << y;
				total_method = w1;
				cout << '<' << endl;
			}
			else {
				path[y] |= 1 << x;
				total_method = w2;
				cout << '>' << endl;
			}
		}
		else {
			vector<int> p(n);
			for (auto &x: p) cin >> x, x --;

			vector<int> indeg(n);

			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < n; j ++) {
					if (path[i] >> j & 1) {
						indeg[j] ++;
					}
				}
			}

			vector<int> cur, stk;

			for (int i = 0; i < n; i ++) {
				if (indeg[i] == 0) {
					stk.emplace_back(i);
				}
			}

			for (int i = 0; i < n; i ++) {
				if (stk.size() > 1 && stk.back() == p[cur.size()])
					reverse(stk.begin(), stk.end());
				
				int u = stk.back();
				stk.pop_back();
				cur.emplace_back(u);

				for (int v = 0; v < n; v ++) {
					if (path[u] >> v & 1) {
						indeg[v] --;
						if (indeg[v] == 0) stk.emplace_back(v);
					}
				}
			}

			cout << '!';
			for (auto &x: cur) cout << ' ' << x + 1;
			cout << endl;

			break;
		}
	}

	return 0;
}