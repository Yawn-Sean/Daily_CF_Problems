#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<pair<int, int>> ops;

	auto operate = [&] (int i, int j) -> void {
		if (i != j) {
			nums[i] ^= nums[j];
			ops.emplace_back(i + 1, j + 1);
		}
	};

	auto swap_zero = [&] (int i, int j) -> void {
		if (i != j) {
			operate(i, j);
			operate(j, i);
		}
	};

	for (int i = 0; i < 100; i ++) {
		int u = rng(), v = rng();
		u = abs(u) % n, v = abs(v) % n;
		operate(u, v);
	}

	vector<int> dp(1 << 21, 0);
	for (int i = 1; i < (1 << 21); i ++) {
		int v = i & -i;
		dp[i] = dp[i - v] ^ nums[__builtin_ctz(v)];
	}

	for (int i = 1; i < (1 << 21); i ++) {
		if (dp[i] == 0) {
			vector<int> idxs;
			for (int j = 0; j < 21; j ++) {
				if (i >> j & 1) {
					idxs.emplace_back(j);
				}
			}

			for (int j = 1; j < idxs.size(); j ++)
				operate(idxs[0], idxs[j]);
			swap_zero(idxs[0], 0);

			break;
		}
	}

	vector<int> pos(n), val(n);

	iota(pos.begin(), pos.end(), 0);
	stable_sort(pos.begin(), pos.end(), [&] (int i, int j) {return nums[i] < nums[j];});

	for (int i = 0; i < n; i ++)
		val[pos[i]] = i;
	
	for (int i = 1; i < n; i ++) {
		if (val[i] != i) {
			swap(pos[val[0]], pos[val[i]]);
			swap(val[0], val[i]);
			swap_zero(0, i);

			int cur = i;
			while (val[0] != cur) {
				int ncur = pos[cur];
				swap(pos[val[cur]], pos[val[ncur]]);
				swap(val[cur], val[ncur]);
				swap_zero(cur, ncur);
				cur = ncur;
			}

			swap(pos[val[0]], pos[val[cur]]);
			swap(val[0], val[cur]);
			swap_zero(cur, 0);
		}
	}

	cout << ops.size() << '\n';
	for (auto &[x, y]: ops) cout << x << ' ' << y << '\n';

	return 0;
}