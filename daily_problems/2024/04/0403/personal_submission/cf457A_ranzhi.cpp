#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<ll> ans(max(n, m));
	for (int i = 0, j = n - 1; i < n; i++, j--) {
		if (s[i] == '1') ans[j] += 1;
	}
	for (int i = 0, j = m - 1; i < m; i++, j--) {
		if (t[i] == '1') ans[j] -= 1;
	}
	for (int i = max(n, m) - 1; i >= 2; i--) {
		if (ans[i] > 1) {
			cout << ">" << endl;
			return 0;
		}
		else if (ans[i] < -1) {
			cout << "<" << endl;
			return 0;
		}
		ans[i - 1] += ans[i];
		ans[i - 2] += ans[i];
	}
	ll res = ans[0] + (ans.size() > 1 ? (ll)2 * ans[1] : 0);
	if (res == 0) cout << "=" << endl;
	else if (res < 0) cout << "<" << endl;
	else cout << ">" << endl;
	return 0;
}
