#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*	 
		The choice is on one of the given points.
	*/
	int n, m;
	cin >> n >> m;
	vector<i64> p(n);
	for (auto& x: p) { cin >> x; }
	
	// 0 m 2m 3m [x] 4m ... ?m
	vector<i64> pre(n), suf(n);
	for (int i = 0; i < n; i++) {
		if (i > 0)	pre[i] = pre[i - 1];
		if (i % m == m - 1) {
			// m pos
			pre[i] += p[i - m + 1];
		}
		// cout << pre[i] << ' ';
	}
	// cout << endl;
	
	for (int i = n - 1; i >= 0; i--) {
		if (i + 1 < n)	suf[i] = suf[i + 1];
		if ((n - 1 - i) % m == m - 1) {
			// m pos
			suf[i] += p[i + (m - 1)];
		}
		// cout << suf[i] << ' ';
	}
	// cout << endl;
	
	i64 ans = 1e18;
	for (int i = 0; i < n; i++) {
		i64 tmp = 1ll * (i + 1) / m * p[i] - pre[i];
		tmp += suf[i] - 1ll * (n - i) / m * p[i];
		
		// [0...i] [i..n-1]
		// <=i的第一个位置 >=i的第一个位置 %m=0
		int left = (i + 1) / m * m, right = n - 1 - (n - i) / m * m;
		if (right - left < m) {
			if (left <= right) {
				tmp += p[max(right, i)] - p[min(left, i)];
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans * 2ll;
	return 0;
}
