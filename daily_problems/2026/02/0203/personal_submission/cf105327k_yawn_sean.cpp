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

	int n;
	cin >> n;

	int total = 0;
	vector<int> nums(n);

	for (auto &v: nums) cin >> v, total += v;

	if (total & 1) cout << -1;
	else {
		int M = total / 2;

		vector<int> dp(M + 1, -2);
		dp[0] = -1;

		for (int i = 0; i < n; i ++) {
			int x = nums[i];
			for (int j = M; j >= x; j --) {
				if (dp[j - x] != -2 && dp[j] == -2) {
					dp[j] = i;
				}
			}
		}

		if (dp[M] == -2) cout << -1;
		else {
			vector<int> vis(n, 0);
			int cur = M;

			while (cur) {
				vis[dp[cur]] = 1;
				cur -= nums[dp[cur]];
			}

			vector<int> v1, v2;
			for (int i = 0; i < n; i ++) {
				if (vis[i]) v1.emplace_back(nums[i]);
				else v2.emplace_back(nums[i]);
			}

			int s1 = 0, s2 = 0, pt1 = 0, pt2 = 0;

			while (pt1 < v1.size() || pt2 < v2.size()) {
				if (s1 <= s2) {
					cout << v1[pt1] << ' ';
					s1 += v1[pt1];
					pt1 ++;
				}
				else {
					cout << v2[pt2] << ' ';
					s2 += v2[pt2];
					pt2 ++;
				}
			}
		}
	}

	return 0;
}