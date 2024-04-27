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
	int n; cin >> n;
	vector<PII> pre(n + 1), suf(n + 1);
	pre[0] = suf[n] = { -1, INT_MAX };
	vector<PII> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	for (int i = 1; i <= n; i++) {
		pre[i].first = max(pre[i - 1].first, arr[i - 1].first);
		pre[i].second = min(pre[i - 1].second, arr[i - 1].second);
	}
	for (int i = n - 1; i >= 0; i--) {
		suf[i].first = max(suf[i + 1].first, arr[i].first);
		suf[i].second = min(suf[i + 1].second, arr[i].second);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = max(pre[i - 1].first, suf[i].first);
		int right = min(pre[i - 1].second, suf[i].second);
		ans = max(ans, right - left);
	}
	cout << ans << endl;
	return 0;
}
