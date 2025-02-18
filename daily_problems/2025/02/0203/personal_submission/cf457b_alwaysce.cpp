#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto&x: a) { cin >> x; }
	for (auto&x: b) { cin >> x; }
	
	i64 suma = accumulate(a.begin(), a.end(), 0ll);
	i64 sumb = accumulate(b.begin(), b.end(), 0ll);
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	
	i64 ans = suma + sumb - max(a[0], b[0]);	
	i64 cur = sumb;
	for (int i = 0; i < m; i++) {
		i64 dif1 = b[i];
		i64 dif2 = 1ll * suma;
		if (dif1 > dif2) {
			cur += -dif1 + dif2;
			ans = min(ans, cur);
		} else {
			break;
		}
	}
	
	cur = suma;
	for (int i = 0; i < n; i++) {
		i64 dif1 = a[i];
		i64 dif2 = 1ll * sumb;
		if (dif1 > dif2) {
			cur += - dif1 + dif2;
			ans = min(ans, cur);
		} else {
			break;
		}
	}
	cout << ans;
	return 0;
}
