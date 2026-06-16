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
		int n, q;
		cin >> n >> q;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<int> next_pos1(n, n), pos(n + 2, n);
		vector<vector<int>> next_pos(20, vector<int>(n + 1, n));

		for (int i = n - 1; i >= 0; i --) {
			next_pos[0][i] = pos[nums[i] + 1];
			pos[nums[i]] = i;
			next_pos1[i] = pos[1];
		}

		for (int i = 0; i < 19; i ++) {
			for (int j = 0; j < n; j ++) {
				next_pos[i + 1][j] = next_pos[i][next_pos[i][j]];
			}
		}

		for (int i = 0; i < q; i ++) {
			int l, r;
			cin >> l >> r;
			l --, r --;

			if (next_pos1[l] > r) cout << 1;
			else {
				l = next_pos1[l];
				int res = 2;

				for (int i = 19; i >= 0; i --) {
					if (next_pos[i][l] <= r) {
						l = next_pos[i][l];
						res += 1 << i;
					}
				}

				cout << res;
			}

			cout << " \n"[i == q - 1];
		}
	}

	return 0;
}