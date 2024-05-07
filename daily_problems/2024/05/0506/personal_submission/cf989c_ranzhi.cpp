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
	int a, b, c, d; cin >> a >> b >> c >> d;
	a -= 1, b -= 1, c -= 1, d -= 1;
	vector<string> ans(50);
	for (int i = 0; i <= 24; i++) ans[i] = string(25, 'A') + string(25, 'B');
	for (int i = 25; i < 50; i++) ans[i] = string(25, 'C') + string(25, 'D');
	for (int i = 1; i < 50; i += 2) {
		if (i == 25) i = 26;
		for (int j = 1; j < 50; j += 2) {
			if (j == 25) j = 26;
			if (i < 25 && j < 25) {
				if (b) ans[i][j] = 'B', b -= 1;
				else if (c) ans[i][j] = 'C', c -= 1;
				else if (d) ans[i][j] = 'D', d -= 1;
			}
			if (i < 25 && j >= 25) {
				if (a) ans[i][j] = 'A', a -= 1;
				else if (c) ans[i][j] = 'C', c -= 1;
				else if (d) ans[i][j] = 'D', d -= 1;
			}
			if (i >= 25 && j < 25) {
				if (b) ans[i][j] = 'B', b -= 1;
				else if (a) ans[i][j] = 'A', a -= 1;
				else if (d) ans[i][j] = 'D', d -= 1;
			}
			if (i >= 25 && j >= 25) {
				if (a) ans[i][j] = 'A', a -= 1;
				else if (c) ans[i][j] = 'C', c -= 1;
				else if (b) ans[i][j] = 'B', b -= 1;
			}
		}
	}
	cout << "50 50" << endl;
	for (auto& x : ans) cout << x << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; t = 1;
	while (t--) solve();
	return 0;
}
