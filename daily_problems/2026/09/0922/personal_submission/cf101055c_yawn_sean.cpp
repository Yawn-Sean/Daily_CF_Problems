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

	int M = 2e5;

	vector<int> is_prime(M, 1);
	is_prime[0] = 0, is_prime[1] = 0;

	vector<int> miu(M, 1);

	for (int i = 1; i <= M; i ++) {
		if (is_prime[i]) {
			for (int j = i; j <= M; j += i) {
				is_prime[j] = 0;
				miu[j] *= -1;
				if (j / i % i == 0) miu[j] = 0;
			}
		}
	}

	vector<int> chosen;
	for (int i = 1; i < M; i ++) if (miu[i]) chosen.emplace_back(i);

	int t;
	cin >> t;

	while (t --) {
		long long target;
		cin >> target;

		long long l = 1, r = 4e10;

		while (l <= r) {
			long long mid = (l + r) / 2, cnt = 0;
			for (auto &x: chosen) {
				cnt += miu[x] * (mid / x / x);
			}
			if (cnt >= target) r = mid - 1;
			else l = mid + 1;
 		}

		cout << l << '\n';
	}

	return 0;
}