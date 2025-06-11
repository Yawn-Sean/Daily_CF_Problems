#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;
i64 inf = 1e18;

i64 dfs(i64 n, i64 l, i64 r) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	// L = 2^k - 1
	i64 ans = 0;
	i64 v = 63 - __builtin_clzll(n);
	i64 len = (1ll << v) - 1;
	if (l < len) {
		ans += dfs(n / 2, l, min(r, len - 1));
	}
	if (l <= len and len <= r) {
		ans += n & 1;
	}
	if (len < r) {
		ans += dfs(n / 2, max(l - len - 1, 0ll), r - len - 1);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, l, r;
	cin >> n >> l >> r;
	--l; --r;
	cout << dfs(n, l, r) << '\n';
	return 0;
}
