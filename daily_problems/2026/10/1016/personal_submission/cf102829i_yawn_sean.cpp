#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e6 + 5, mod = 1e9 + 7;
	vector<int> f(M), g(M);

	f[0] = 1;
	for (int i = 1; i < M; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);
	for (int i = M - 1; i >= 1; i --) g[i - 1] = 1ll * i * g[i] % mod;

	int t;
	cin >> t;

	while (t --) {
		int x, y;
		cin >> x >> y;
		x = abs(x) + 1;
		y = abs(y) + 1;
		cout << 1ll * f[x + y] * g[x] % mod * g[y] % mod - 1 << '\n';
	}

	return 0;
}