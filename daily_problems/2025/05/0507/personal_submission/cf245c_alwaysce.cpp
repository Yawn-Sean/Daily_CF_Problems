#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3 || (n % 2) == 0) {
		cout << -1;
		return 0;
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] > 0) {
			ans += a[i];
			int fi = i / 2;
			a[fi] -= a[i];
			if (i > 1 && i & 1) {
				a[i - 1] -= a[i];
			}			
		}
	}
	cout << ans << endl;
	return 0;
}
