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

	vector<int> nums(n), target;
	vector<vector<int>> pos(m + 1);

	for (int i = 0; i < n; i ++) {
		cin >> nums[i];
		pos[nums[i]].emplace_back(i);
	}

	for (int i = 0; i <= m; i ++) {
		if (!pos[i].empty()) {
			target.emplace_back(i);
		}
	}

	int k = target.size(), start = 0, ans = 0;

	while (start < k) {
		int nstart1 = 0, cur1 = 0;

		for (int j = start; j < k; j ++) {
			int p = lower_bound(pos[target[j]].begin(), pos[target[j]].end(), cur1) - pos[target[j]].begin();
			if (p == pos[target[j]].size()) break;
			nstart1 = j;
			cur1 = pos[target[j]][p];
		}

		int nstart2 = 0, cur2 = n;

		for (int j = start; j < k; j ++) {
			int p = lower_bound(pos[target[j]].begin(), pos[target[j]].end(), cur2) - pos[target[j]].begin() - 1;
			if (p == -1) break;
			nstart2 = j;
			cur2 = pos[target[j]][p];
		}

		start = max(nstart1, nstart2) + 1;
		ans ++;
	}

	cout << k << ' ' << ans;

	return 0;
}