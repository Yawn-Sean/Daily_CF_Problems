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

	int M = 1e6 + 100;

	vector<int> isPrime(M, 1);
	isPrime[0] = 0, isPrime[1] = 0;

	for (int i = 2; i < M; i ++) {
		for (int j = i * 2; j < M; j += i) {
			isPrime[j] = 0;
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> ans(n);
		int l = 0, r = n - 1;

		while (n) {
			for (int x = 1; x <= n; x ++) {
				if (isPrime[n + x]) {

					for (int i = x; i <= n; i ++) {
						if (i > n + x - i) break;
						ans[l ++] = i;
						ans[r --] = n + x - i;
					}

					n = x - 1;
					break;
				}
			}
		}

		for (auto &v: ans) cout << v << ' '; cout << '\n';
	}

	return 0;
}