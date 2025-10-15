#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;
	int g = gcd(a, b);
	a /= g;
	b /= g;
	int q = min(n / a, m / b);
	int dx = a * q, dy = b * q;
	int lx = max(0, min(x - (dx + 1) / 2, n - dx)), ly = max(0, min(y - (dy + 1) / 2, m - dy));
	int rx = lx + dx, ry = ly + dy;
	cout << lx << " " << ly << " " << rx << " " << ry << "\n";
	return 0;
}