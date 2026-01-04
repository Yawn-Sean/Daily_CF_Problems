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

	int M = 1e5, mod = 1e9 + 7, rev2 = (mod + 1) / 2;
	vector<int> pw2(M + 1);
	
	pw2[0] = 1;
	for (int i = 0; i < M; i ++) pw2[i + 1] = 2ll * pw2[i] % mod;

	int t;
	cin >> t;

	while (t --) {
		int d;
		cin >> d;

		int ans = 0, edges = 1, total = pw2[d] - 1, cur = total;

		for (int i = 0; i < d - 1; i ++) {
			cur = 1ll * (cur - 1) * rev2 % mod;
			edges = 2ll * edges % mod;

			ans = (ans + 1ll * cur * (mod + total - cur) % mod * edges % mod) % mod;
		}

		cout << 2ll * ans % mod << '\n';
	}

	return 0;
}