#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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
		int n, k;
		long long x;
		cin >> n >> k >> x;

		vector<long long> acc(n + 1, 0);

		for (int i = 1; i <= n; i ++) {
			long long l = max(-1ll * (n - i) * k, acc[i - 1] - k);
			long long r = max(0ll, acc[i - 1] + k);

			while (l <= r) {
				long long mid = (l + r) / 2;
				long long start = -mid, step = start / k;
				if ((start + start + step * (-k)) * (step + 1) / 2 <= x) r = mid - 1;
				else l = mid + 1;
			}

			acc[i] = l; x += l;
		}

		for (int i = 1; i <= n; i ++) cout << acc[i] - acc[i - 1] << " \n"[i == n];
	}

	return 0;
}