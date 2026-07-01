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

	int M = 1e6 + 5;
	vector<int> isPrime(M, 1), primes;
	
	for (int i = 2; i < M; i ++) {
		if (isPrime[i]) {
			primes.emplace_back(i);
			for (int j = i; j < M; j += i) {
				isPrime[j] = 0;
			}
		}
	}

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		long long n;
		cin >> n;

		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}

		vector<long long> pr;
		long long cur = n;

		for (auto &i: primes) {
			if (1ll * i * i > cur) break;
			if (cur % i == 0) {
				pr.emplace_back(i);
				while (cur % i == 0) {
					cur /= i;
				}
			}
		}

		if (cur > 1) pr.emplace_back(cur);
		
		long long total;

		if (pr.size() == 1)
			total = ((pr[0] - 1) % mod) * (pr[0] % mod) % mod * (mod + 1) / 2 % mod;
		else {
			total = 0;
			
			for (int i = 1; i < pr[0]; i ++) {
				long long res = 1;
				for (auto &x: pr) {
					res = res * (x - i) % mod;
				}
				total = (total + res) % mod;
			}
		}

		for (auto &p: pr) n /= p;
		cout << n * total % mod << '\n';
	}

	return 0;
}