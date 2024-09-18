#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 pow(i64 base, i64 exp, i64 mod) {
	base %= mod;
	i64 ans = 1;
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
	
	int n;
	cin >> n;
	vector<int> p(n), used(n + 1);
	
	i64 mod = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		if (p[i] > 0) {
			used[p[i]] = 1;
		}
	}
	
	vector<i64> f(n + 1, 1), g(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		f[i] = 1ll * f[i - 1] * i % mod;
	}
	g[n] = pow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i--) {
		g[i - 1] = 1ll * g[i] * i % mod;
	}
	
	// 容斥原理
	// 可能出现在不合法位置上的数字 = x0
	i64 x0 = 0, x1 = 0;
	for (int i = 1; i <= n; i++) {
		// 当前这个数字没有出现
		if (!used[i]) {
			// 已经被占用了 随便放
			if (p[i - 1] > 0) {
				x1++;
			} else {
				x0++;
			}
		}
	}
	
	i64 ans = 0, fl = 1ll;
	// 当前位置为i i位置没有使用 且f[i]也没有用过
	// x0个位置上元素恰好不等它的下标 = sum(flag * (x1 + i)! * comb(x0, i))
	// x1个元素可以随便选 x0-i个元素也随便选
	// 剩下i个位置 选法有comb(x0, i)种
	for (int i = 0; i <= x0; i++) {
		ans += 1ll * fl * f[x0 + x1 - i] % mod * f[x0] % mod * g[i] % mod * g[x0 - i] % mod;
		fl = -fl;
		ans %= mod;
		ans = (ans + mod) % mod;
	}
	cout << ans;
    return 0;
}
