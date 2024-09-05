// Author:	Kexuan Miao
// Time:	2024-09-03 Tue 11:17 PM
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	if (k > (n-1)+(m-1)) {
		cout << -1 << '\n';
		return;
	}
	ll ans = max(1LL, n / (min(k,n-1) + 1) * (m / (k-min(k,n-1)+1)));
	ans = max(ans, m / (min(k,m-1)+1) * (n / (k-min(k,m-1)+1)));
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
