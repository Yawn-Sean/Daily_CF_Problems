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

    int M = 3e5, mod = 1e9 + 7;
    vector<int> f(M + 1);

    f[0] = 1;
    for (int i = 1; i <= M; i ++) f[i] = 1ll * i * f[i - 1] % mod;

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        int ans = 1ll * f[n / 2] * f[n - n / 2] % mod;
        if (n & 1) ans = 1ll * (n / 2 + 1) * (n / 2 + 2) / 2 % mod * ans % mod;
        else ans = 1ll * (n / 2 + 1) * ans % mod;

        cout << ans << '\n';
    }

	return 0;
}