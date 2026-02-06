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

	int p, x, y;
	long long a;
	cin >> p >> x >> y >> a;

	vector<int> mods = {1};
	
	for (int i = 0; i < p; i ++) {
		mods.emplace_back(1ll * mods.back() * x % p);

		if (mods.back() == 1) {
			mods.pop_back();
			break;
		}
	}

	int k = mods.size();
	vector<int> pos(p, -1);

	for (int i = 0; i < k; i ++)
		pos[mods[i]] = i;

	long long ans = 0, cycle = 1ll * k * p;
	for (int i = 1; i < p; i ++) {
		int v = quickPow(i, p - 2, p) * y % p;
		if (pos[v] >= 0) {
			long long res = (1ll * (pos[v] - i) * p + i) % cycle;
			if (res < 0) res += cycle;
			if (a >= res) ans += (a - res) / cycle + 1;
		}
	}

	cout << ans;

	return 0;
}