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
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ans = n, pre_maxn = INT_MAX;
	for (int i = 0; i + k < n; i++) {
		int t = (arr[i] + arr[i + k]) / 2;
		if (arr[i + k] - t < pre_maxn) {
			pre_maxn = arr[i + k] - t;
			ans = t;
		}
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
