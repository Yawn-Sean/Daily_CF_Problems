#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

i64 pow(i64 base, i64 exp) {
	base %= mod;
	i64 ans = 1ll;
	while (exp) {
		if (exp & 1) {
			ans = ans * base % mod;
		}
		base = base * base % mod;
		exp >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, m, a;
	cin >> n >> m >> a;
	
	i64 ans = 1, cur = 0;
	while (m--) {
		i64 num;
		cin >> num;
		// C(|A|^k + 1, 2)
		i64 v = pow(a, num - cur);
		ans = 1ll * v * (v + 1) / 2 % mod * ans % mod;
		cur = num;
	}
	// 剩下随便填 a^(n - 2bm)
	cout << pow(a, n - cur * 2) * ans % mod;
    return 0;
}
