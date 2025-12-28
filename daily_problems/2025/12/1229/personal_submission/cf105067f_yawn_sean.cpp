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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long l, r;
	cin >> n >> l >> r;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<vector<int>> cnt(2, vector<int>(17, 0));

	for (auto &x: nums) {
		for (int i = 0; i < 17; i ++) {
			cnt[x >> i & 1][i] ++;
		}
	}

	long long M = 1 << 17;
	vector<long long> saved(M, 0);

	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < 17; j ++) {
			saved[i] += (1ll << j) * cnt[(i >> j & 1) ^ 1][j];
		}
	}

	sort(saved.begin(), saved.end());

	auto floor_div = [&] (long long x, long long y) -> long long {
		long long res = x / y;
		if (res * y > x) res --;
		return res;
	};

	long long ans = 0;
	for (int i = 0; i < M; i ++) {
		if (i == 0 || saved[i] != saved[i - 1]) {
			ans += floor_div(r - saved[i], M * n) - floor_div(l - 1 - saved[i], M * n);
		}
	}

	cout << ans;

	return 0;
}