#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;
using mint = atcoder::modint998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 1e6;
	vector<mint> f(M + 1), g(M + 1);

	f[0] = 1;
	for (int i = 1; i <= M; i ++) f[i] = i * f[i - 1];
	
	g[M] = 1 / f[M];
	for (int i = M; i >= 1; i --) g[i - 1] = i * g[i];

	auto comb = [&] (int x, int y) -> mint {
		if (y < 0 || y > x) return mint(0);
		return f[x] * g[y] * g[x - y];
	};

	int t;
	cin >> t;

	while (t --) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		mint ans = comb(a + d - 2, a - 2) * comb(b + c, b);
		if (a + d - b - c == 1) ;
		else if (a + d - b - c == 0) ans *= 2;
		else ans = 0;

		cout << ans.val() << '\n';
	}

	return 0;
}