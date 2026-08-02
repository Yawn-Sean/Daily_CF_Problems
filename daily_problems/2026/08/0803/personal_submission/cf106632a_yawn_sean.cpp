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

	int M = 1e6 + 5;
	vector<int> isPrime(M, 1), cnt(M, 0);

	isPrime[0] = 0, isPrime[1] = 0;
	cnt[1] = 1;

	for (int i = 2; i < M; i ++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < M; j += i)
				isPrime[j] = 0;
			
			int cur = i, c = 1;
			while (true) {
				if (__popcount(c) == 1) cnt[cur] = 1;
				if (cur > (M - 1) / i) break;
				cur *= i, c ++;
			}
		}
	}

	for (int i = 1; i < M; i ++) cnt[i] += cnt[i - 1];

	int t; cin >> t;

	while (t --) {
		int n; cin >> n;
		cout << cnt[n] << '\n';
	}

	return 0;
}