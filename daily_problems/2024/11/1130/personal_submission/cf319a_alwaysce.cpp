#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;

i64 mod = 1e9+7;

i64 pow(i64 base, i64 exp, i64 mod) {
	i64 ans = 1ll;
	base %= mod;
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
	
	string x;
	cin >> x;
	
	int n = x.size();	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] == '1') {
			// [0, 2^i-1], [2^i, 2^{i+1}-1]
			ans = (ans + pow(2, 2*n-i-2, mod)) % mod;
		}
	}
	cout << ans % mod;
	return 0;
}
