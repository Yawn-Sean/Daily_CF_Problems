#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	
	int g = gcd(a, b);
	a /= g;
	b /= g;
	
	int k = min(n / a, m / b);
	
	int h = k * a, w = k * b;
	// cout << h << " " << w << endl;
	
	int x0 = x - ((h + 1) / 2);
	int y0 = y - ((w + 1) / 2);
	x0 = max(x0, 0);
	y0 = max(y0, 0);
	
	x0 = min(x0, n - h);
	y0 = min(y0, m - w);
	
	cout << x0 << ' ' << y0 << ' ' << x0 + h << ' ' << y0 + w << endl;
	return 0;
}
