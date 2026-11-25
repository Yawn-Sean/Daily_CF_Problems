#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;
using mint = atcoder::modint998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 1e5;
	vector<mint> f(M + 1), g(M + 1);

	f[0] = 1;
	for (int i = 1; i <= M; i ++) f[i] = i * f[i - 1];
	g[M] = 1 / f[M];
	for (int i = M; i >= 1; i --) g[i - 1] = i * g[i];

	int t;
	cin >> t;

	while (t --) {
		int n, k, P;
		cin >> n >> k >> P;

		mint p = P; p /= 100;
		mint ans = 0;

		for (int i = 0; i <= k; i ++) {
			mint prob = 1 - mint(n - i) / n * p;
			mint cur = f[k] * g[i] * g[k - i] * prob.pow(n);
			if ((k - i) % 2 == 0) ans += cur;
			else ans -= cur;
		}
		
		ans = ans * f[n] * g[k] * g[n - k];
		cout << ans.val() << '\n';
	}

	return 0;
}