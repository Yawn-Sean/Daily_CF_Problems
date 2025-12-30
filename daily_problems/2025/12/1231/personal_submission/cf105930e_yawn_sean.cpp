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

	int t;
	cin >> t;

	while (t --) {
		int n;
		long long k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int ma = *max_element(nums.begin(), nums.end());
		vector<int> acc_cnt(ma + 1, 0);
		long long total = k;

		for (auto &x: nums) {
			total += x;
			acc_cnt[x] ++;
		}

		for (int i = 1; i <= ma; i ++)
			acc_cnt[i] += acc_cnt[i - 1];

		auto check = [&] (long long x) -> bool {
			if (x >= ma) return x * acc_cnt[ma] <= total;
			long long val = 0;
			for (int i = 0; i <= ma; i += x)
				val += (acc_cnt[min(i + x, (long long)ma)] - acc_cnt[i]) * (i + x);
			return val <= total;
		};

		long long ans = 0;

		for (long long i = 1; i * i <= total; i ++) {
			if (total % i == 0) {
				if (check(i)) ans = max(ans, i);
				if (check(total / i)) ans = max(ans, total / i);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}