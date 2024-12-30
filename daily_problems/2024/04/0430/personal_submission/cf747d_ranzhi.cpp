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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> arr(n + 1), diff;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int cnt = 0, l = -1, pre = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] < 0) {
			cnt += 2;
			if (pre) diff.push_back(i - pre - 1);
			l = pre = i;
			m--;
		}
	}
	if (m < 0) return cout << "-1" << endl, 0;
	sort(diff.begin(), diff.end());
	for (auto &x : diff) {
		if (m < x) break;
		m -= x;
		cnt -= 2;
	}
	if (n - l <= m) cnt -= 1;
	cout << cnt << endl;
	return 0;
}
