#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*

	*/
	int t;
	cin >> t;
	while (t--) {
		double a, b;
		cin >> a >> b;
		
		if (a == 0.0) {
			if (b == 0.0) {
				cout << fixed << setprecision(10) << 1.0 << '\n';
			} else {
				cout << fixed << setprecision(10) << 0.5 << '\n';
			}
			continue;
		}
		if (b == 0.0) {
			cout << fixed << setprecision(10) << 1.0 << '\n';
			continue;
		}
		
		
		double tot = 1.0 * b * a;
		
		double rx = min(0.25 * a, 1.0 * b);
		double ry = 4.0 * rx;
		if (ry < a) {
			tot += (a - ry) * rx;			
		}
		tot += 0.5 * rx * ry;
		
		double ans = tot / (2.0 * a * b);
		cout << fixed << setprecision(10) << ans << '\n';
	}
	return 0;
}
