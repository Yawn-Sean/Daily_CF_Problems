#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int MOD = 998244353, N = 200010;

int a[N], b[N], x[N], y[N];

void solve() {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < q; i ++) {
		cin >> x[i] >> y[i];
		x[i] --; y[i] --;
	}
	int ans = 1;
	for (int i = q - 1, u = 0, v = 0; i >= 0 && (v < m || u < n); i --) {
		int can = 0;
		if (!a[x[i]] && v < m) {
			can = 1;
			u ++;
		}
		if (!b[y[i]] && u < n) {
			can = 1;
			v ++;
		}
		if (can) {
			ans = 1LL * ans * k % MOD;
		}
		a[x[i]] = b[y[i]] = 1;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T -- ) {
		solve();
	}
	return 0;
}
