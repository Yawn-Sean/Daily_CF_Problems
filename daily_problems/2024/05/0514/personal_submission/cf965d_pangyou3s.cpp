#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
	int w, l;
	cin >> w >> l;
	vector<int> a(w);
	for (int i = 1; i < w; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int ans = 0x3f3f3f3f;
	for (int i = l; i < w; i++) ans = min(ans, a[i] - a[i - l]);
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
