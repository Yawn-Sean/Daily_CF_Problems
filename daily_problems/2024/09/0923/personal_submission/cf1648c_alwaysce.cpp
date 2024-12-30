#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

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
	
	// 长度=l的前缀一致
	// s[l+1] < t[l+1]
	// 可选的字符数量 = s中剩余的 < t[l+1]的个数
	// 后面可以选的方案书 = (n - l - 1)! / (cj!)
	// cj为剩下还有的字符
	
	int M = 2e5+5;
	vector<i64> f(M + 1, 1), g(M + 1, 1);
	for (int i = 1; i <= M; i++) {
		f[i] = f[i - 1] * i % mod;
	}
	g[M] = pow(f[M], mod - 2);
	
	for (int i = M; i >= 1; i--) {
		g[i - 1] = g[i] * i % mod;
	}
	
	int n, m;
	cin >> n >> m;

	vector<int> cnt(M);
	Fenwick<int> fen(M);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		fen.add(x, 1);
	}
	
	i64 cur = f[n];
	for (auto& x: cnt) {
		// n! / cj1!*cj2!*...
		cur = cur * g[x] % mod;
	}
	
	// t[1], t[2], ...
	i64 ans = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (i >= n) {
			ans++;
			ans %= mod;
			break;
		}
		// 1/(n-i) = (n - i - 1)! / (n - i)!
		cur = cur * f[n - i - 1] % mod * g[n - i] % mod;
		// <x的个数 * (n-l-1)!/(cj!)
		ans += cur * fen.sum(x) % mod;
		
		// 剩下全都不能匹配上t[l+1]
		if (cnt[x] == 0) break;
		// 用掉了一个x
		cur = cur * cnt[x] % mod;
		cnt[x]--;
		fen.add(x, -1);
	}
	
	cout << ans % mod;
	return 0;
}
