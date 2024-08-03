#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
#define endl '\n'

void solve() {
	int n; cin >> n;
	unordered_map<int, int> mp;
	int right = 1e9, ind = 0;
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		mp[a] += 1;
	}
	for (auto& x : mp) right = min(right, x.second);
	for (int i = 1; i <= right + 1; i++) {
		bool flag = true;
		int res = 0;
		for (auto& x : mp) {
			int t = (x.second - 1) / i + 1;
			if (t * (i - 1) <= x.second) res += t;
			else {
				flag = false;
				break;
			}
		}
		if (flag) ans = min(ans, res);
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
