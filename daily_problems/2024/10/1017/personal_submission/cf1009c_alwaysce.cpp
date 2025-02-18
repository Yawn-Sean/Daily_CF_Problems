#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	i64 mx = 1ll * n * (n - 1) / 2;
	i64 mn = 0;
	for (int i = 1; i <= n; i++) {
		mn += abs(i - (1 + n) / 2);
	}
	// cout << mn << ' ' << mx << '\n';
	
	i64 tot = 0, base = 0;
	for (int i = 0; i < m; i++) {
		int x, d;
		cin >> x >> d;
		base += x;
		if (d > 0) {
			tot += mx * d;
		} else {
			tot += mn * d;
		}
	}
	
	double ans = base;
	ans += 1.0 * tot / n;
	cout << fixed << setprecision(10) << ans;
    return 0;
}
