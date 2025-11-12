#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

#include "atcoder/fenwicktree"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (!n) break;

		vector<int> nums(2 * n);
		vector<vector<int>> pos(n + 1);

		for (int i = 0; i < 2 * n; i ++) {
			cin >> nums[i];
			pos[nums[i]].emplace_back(i);
		}

		vector<int> target(2 * n, -1);
		for (int i = 0; i <= n; i ++) {
			int k = pos[i].size() / 2;
			for (int j = 0; j < k; j ++) {
				target[pos[i][j]] = pos[i][j + k];
			}
		}

		atcoder::fenwick_tree<int> fen(2 * n);
		long long ans = 1ll * n * (n - 1) / 2;

		for (int i = 0; i < 2 * n; i ++) {
			if (target[i] != -1) {
				ans -= fen.sum(i, target[i]);
				fen.add(target[i], 1);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}