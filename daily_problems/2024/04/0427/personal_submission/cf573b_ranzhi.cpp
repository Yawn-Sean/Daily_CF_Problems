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
	vector<int> arr(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = min(arr[i - 1] + 1, arr[i]);
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		arr[i] = min(arr[i + 1] + 1, arr[i]);
		ans = max(ans, arr[i]);
	}
	cout << ans << endl;
	return 0;
}
