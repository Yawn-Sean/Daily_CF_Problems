#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n == 1) cout << "1";
	else if (n == 4) cout << "1 3 2 4";
	else {
		bool flg = true;
		for (int i = 2; i < n; i ++) {
			if (n % i == 0) {
				flg = false;
			}
		}

		if (flg) {
			cout << "1 ";
			for (int i = 2; i < n; i ++)
				cout << 1ll * i * quickPow(i - 1, n - 2, n) % n << ' ';
			cout << n;
		}
		else cout << "-1";
	}

	return 0;
}