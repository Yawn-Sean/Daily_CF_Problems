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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e5, mod = 1e9 + 7;
	vector<int> f(M + 1), g(M + 1);

	f[0] = 1;
	for (int i = 1; i <= M; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;

	g[M] = quickPow(f[M], mod - 2, mod);
	for (int i = M; i >= 1; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;
		
		vector<int> pos(n - 1, 1);
		while (k --) {
			int idx;
			cin >> idx;
			idx --;
			pos[idx] = 0;
		}

		int ans = f[n], cur = 1;
		for (auto &x: pos) {
			if (x) cur += x;
			else {
				ans = 1ll * ans * g[cur] % mod;
				cur = 1;
			}
		}

		ans = 1ll * ans * g[cur] % mod;
		cout << ans << '\n';
	}

	return 0;
}