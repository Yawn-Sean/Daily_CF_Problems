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

	int n, m;
	cin >> n >> m;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	vector<long long> ls(m), rs(m), xs(m), ys(m);

	for (int i = 0; i < m; i ++) {
		cin >> ls[i] >> rs[i] >> xs[i] >> ys[i];
		ls[i] --;
	}

	long long bound = 1e13;
	long long l = 0, r = bound;

	vector<long long> sol(n + 1, 0);

	while (l <= r) {
		long long mid = (l + r) / 2;

		for (int _ = 0; _ < n; _ ++) {
			for (int i = 0; i < m; i ++) {
				sol[rs[i]] = max(sol[rs[i]], sol[ls[i]] + xs[i]);
				sol[ls[i]] = max(sol[ls[i]], sol[rs[i]] - ys[i]);
			}
			for (int i = 0; i < n; i ++) {
				sol[i + 1] = max(sol[i + 1], sol[i] + max(1ll, nums[i] - mid));
				sol[i] = max(sol[i], sol[i + 1] - nums[i] - mid);
			}
		}

		bool flg = true;

		for (int i = 0; i < n; i ++) {
			if (!(max(1ll, nums[i] - mid) <= sol[i + 1] - sol[i]) || !(sol[i + 1] - sol[i] <= nums[i] + mid)) {
				flg = false;
			}
		}

		for (int i = 0; i < m; i ++) {
			if (!(xs[i] <= sol[rs[i]] - sol[ls[i]]) || !(sol[rs[i]] - sol[ls[i]] <= ys[i])) {
				flg = false;
			}
		}

		if (flg) r = mid - 1;
		else l = mid + 1;

		for (int i = 0; i <= n; i ++) sol[i] = 0;
	}

	cout << (l < bound ? l : -1);

	return 0;
}