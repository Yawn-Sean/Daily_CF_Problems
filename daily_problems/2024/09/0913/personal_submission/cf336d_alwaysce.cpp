#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9 + 7;

i64 pow(i64 base, i64 exp) {
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
	
	int n, m, g;
	cin >> n >> m >> g;
	
	vector<i64> f(n + m + 1, 1), inv_f(n + m + 1, 1);
	for (int i = 1; i <= n + m; i++) {
		f[i] = f[i - 1] * i % mod; 
	}
	
	inv_f[n + m] = pow(f[n + m], mod - 2);
	for (int i = n + m; i >= 1; i--) {
		inv_f[i - 1] = inv_f[i] * i % mod;
	}
	
	if (m == 0) {
		int cur = 0;
		for (int i = 0; i < n - 1; i++) {
			cur = 1 - cur;
		}
		cout << (cur == g ? 1 : 0);
	} else if (m == 1) {
		i64 ans = 0, cur = 0;
		
		for (int i = 0; i < n; i++) {
			if (cur == g) {
				ans++;
			}
			cur = 1 - cur;
		}
		// 1放最后
		cout << ans + (cur ^ g);
	} else {
		i64 ans = 0, cur = 0;
		// 模拟0 - 1 - 0
		for (int c0 = 0; c0 <= n; c0++) {
			// 发现这个模式可以!
			// 放1在?位置=大于?的地方放什么都可以
			// c(x + y, x)
			// f(0)=0 f(1)=00=1 ...
			if (cur == g) {
				int x = n - c0;
				int y = m - 1;
				ans += f[x + y] * inv_f[x] % mod * inv_f[y] % mod;
				ans %= mod;
			}
			cur = 1 - cur;
		}
		cout << ans << '\n';
	}
	return 0;
}
