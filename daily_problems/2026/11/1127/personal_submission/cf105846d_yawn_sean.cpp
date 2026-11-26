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
 
	vector<mint> ans(M + 1);
	ans[0] = 1;
	
	for (int i = 1; i <= M; i ++) {
		if (i & 1) ans[i] = ans[i - 1] - g[i];
		else ans[i] = ans[i - 1] + g[i];
	}
 
	for (int i = 0; i <= M; i ++) ans[i] *= f[i] * f[i];
 
	int t;
	cin >> t;
 
	while (t --) {
		int n;
		cin >> n;
		cout << ((n & 1) ? ans[n].val() : 1) << '\n';
	}
 
	return 0;
}