#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9 + 7;
i64 pow(i64 base, i64 exp) {
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
	
	i64 x, k;
	cin >> x >> k;
	if (x == 0) {
		cout << 0;
		return 0;
	}
	// 2bx - (b-1)
	// b = 2^k
	x %= mod;
	i64 b = pow(2ll, k);
	i64 ans = (2ll * b % mod) * x % mod;
	ans = (ans - (b - 1ll)) % mod;
	ans = (ans + mod) % mod;
	cout << ans;
    return 0;
}
