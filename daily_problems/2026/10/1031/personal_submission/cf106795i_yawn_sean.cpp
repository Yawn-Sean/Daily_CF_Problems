#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> prs;

	for (int i = 2; i <= 50; i ++) {
		bool flg = true;

		for (int j = 2; j < i; j ++) {
			if (i % j == 0) {
				flg = false;
			}
		}

		if (flg) prs.emplace_back(i);
	}

	int k = prs.size();

	int M = 2501;

	vector<int> tag(M, 0), big(M, 0);

	for (int i = 1; i < M; i ++) {
		int msk = 0, cur = i;

		for (int j = 0; j < k; j ++) {
			while (cur % prs[j] == 0) {
				msk |= 1 << j;
				cur /= prs[j];
			}
		}

		tag[i] = msk;
		if (cur >= 50) big[i] = cur;
	}

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> vis(M, 0);
	int ans = n;

	for (int i = 0; i < (1 << k); i ++) {
		int cur = __popcount(i);
		bool flg = true;

		for (auto &v: nums) {
			if (tag[v] & i) continue;
			if (big[v]) {
				if (!vis[big[v]]) {
					vis[big[v]] = 1;
					cur ++;
				}
			}
			else flg = false;
		}

		if (flg) ans = min(ans, cur);

		for (auto &v: nums) vis[big[v]] = 0;
	}

	cout << ans;

	return 0;
}