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

	int M = 2e5;
	vector<int> pr(M + 1);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int x;
		long long k;
		cin >> x >> k;

		vector<long long> cnt;
		while (x > 1) {
			int p = pr[x];
			long long c = 0;

			while (x % p == 0) {
				x /= p;
				c ++;
			}

			cnt.emplace_back(c);
		}

		int ans = 0, v = 1;
		long long cur = 2;

		while (true) {
			long long tmp = 0;
			for (auto &x: cnt) {
				long long val = (x + cur - 1) / cur;
				tmp += val * cur - x;
				x = val * cur;
			}

			if (tmp > k) break;
			ans = v;

			k -= tmp;
			cur *= 2;
			v ++;
		}

		cout << ans << '\n';
	}

	return 0;
}