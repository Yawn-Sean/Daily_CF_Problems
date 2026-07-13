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

	int n, m;
	cin >> n >> m;

	vector<int> p(n), ts(m);
	for (auto &x: p) cin >> x;
	for (auto &x: ts) cin >> x;

	int M = 2e5 + 5;

	vector<set<int>> updates(M);
	vector<int> next_update(n, 0);
	set<int> cur_possible;

	for (int i = 0; i < n; i ++) {
		int cur = i % (2 * p[i]);

		if (cur < p[i]) {
			cur_possible.insert(i);
			next_update[i] = p[i] - cur;
			updates[p[i] - cur].insert(i);
		}
		else {
			next_update[i] = 2 * p[i] - cur;
			updates[2 * p[i] - cur].insert(i);
		}
	}

	vector<int> ans(m, 0), idxs(m);
	iota(idxs.begin(), idxs.end(), 0);
	sort(idxs.begin(), idxs.end(), [&] (int i, int j) {return ts[i] < ts[j];});

	int pt = 0;

	for (int i = 0; i < 100'005; i ++) {
		for (auto &idx: updates[i]) {
			if (cur_possible.find(idx) == cur_possible.end()) cur_possible.insert(idx);
			else cur_possible.erase(idx);

			next_update[idx] = i + p[idx];
			updates[i + p[idx]].insert(idx);
		}

		updates[i].clear();

		if (pt < m && ts[idxs[pt]] == i) {
			if (cur_possible.empty()) ans[idxs[pt]] = -1;
			else {
				int idx = *cur_possible.begin();
				ans[idxs[pt]] = idx;
				cur_possible.erase(idx);

				updates[next_update[idx]].erase(idx);
				next_update[idx] = i + p[idx] + 1;
				updates[i + p[idx] + 1].insert(idx);
			}
			pt ++;
		}
	}

	for (int i = 0; i < m; i ++) {
		if (ans[i] >= 0) cout << ans[i] << ' ' << ts[i] + ans[i] << '\n';
		else cout << "-1 -1\n";
	}

	return 0;
}