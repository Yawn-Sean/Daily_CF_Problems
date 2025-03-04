#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);
	vector<int>f(m + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<int>k(m + 1);
	int sum = 0;
	int l = 1, r = 1, t = 0;
	for (int i = 1; i <= m; i++) {
		cin >> k[i], sum += k[i];
		if (k[i] == 0) t++;
	}
	// cout<<sum<<endl;

	int ans = 1e18;
	// cout<<ans<<endl;
	while (l <= n) {
		while (r <= n && t < m) {
			f[a[r]]++;
			if (f[a[r]] == k[a[r]]) t++;
			// cout<<l<<' '<<r<<' '<<t<<endl;
			r++;
		}
		if (t < m) break;
		// cout<<l<<' '<<r<<endl;
		ans = min(ans, r - l - sum);
		if (f[a[l]] == k[a[l]]) t--;
		f[a[l]]--;
		l++;
	}
	if (ans == 1e18) cout << -1 << endl;
	else cout << ans << endl;
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
