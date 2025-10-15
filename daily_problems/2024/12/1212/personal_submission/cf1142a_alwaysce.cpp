#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	
	i64 tot = 1ll * n * k;
	i64 mn = tot, mx = 0;
	
	for (int i = 0; i < n; i++) {
		i64 x = 1ll * k * i + a + b;
		i64 tmp = tot / gcd(x, tot);
		mn = min(mn, tmp), mx = max(mx, tmp);
		
		x = 1ll * k * i + a - b;
		tmp = tot / gcd(x, tot);
		mn = min(mn, tmp), mx = max(mx, tmp);
	}
	cout << mn << ' ' << mx;
	return 0;
}
