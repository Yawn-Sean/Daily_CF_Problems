#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

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
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	vector<int> cnt1(n + 1);
	for (int i = 0; i < n; i++) {
		cnt1[i + 1] = cnt1[i] + (s[i] - '0');	
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		
		i64 tmp1 = cnt1[r] - cnt1[l];
		i64 tmp0 = (r - l) - tmp1;
		
		i64 base = (pow(2ll, tmp1) - 1ll) % mod;		
		i64 ans = base;
		
		ans = ans + (base * (pow(2ll, tmp0) - 1ll) % mod) % mod;
		if (ans >= mod) {
			ans -= mod;
		}
		cout << ans << '\n';
	}
    return 0;
}
