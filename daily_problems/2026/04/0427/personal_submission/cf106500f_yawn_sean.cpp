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

	vector<int> cnt(10, 0);
	vector<vector<long long>> pairs(10, vector<long long>(10, 0));

	int n;
	cin >> n;

	while (n --) {
		int x;
		cin >> x;
		x --;

		for (int i = 0; i < 10; i ++)
			pairs[i][x] += cnt[i];
		cnt[x] ++;
	}

	long long inf = 1e14;

	vector<long long> dp(1 << 10, inf);
	dp[0] = 0;

	for (int i = 0; i < (1 << 10); i ++) {
		for (int j = 0; j < 10; j ++) {
			if (i >> j & 1) continue;

			int ni = i | (1 << j);
			long long new_rev = 0;

			for (int k = 0; k < 10; k ++) {
				if (i >> k & 1) {
					new_rev += pairs[k][j];
				}
			}

			dp[ni] = min(dp[ni], dp[i] + new_rev);
		}
	}

	cout << dp.back();

	return 0;
}
