#include<bits/stdc++.h>
using namespace std;
int n, a[105];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	if (n <= 2 || n % 2 == 0) {
		cout << -1;
		return 0;
	}
	for (int i = n; i >= 1; i -= 2) {
		int t = max(a[i], a[i - 1]);
		ans += t;
		int fa = (i - 1) / 2;
		a[fa] = max(0, a[fa] - t);
	}
	cout << ans;
	return 0;
}
