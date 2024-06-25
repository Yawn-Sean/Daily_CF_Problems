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
	vector<PII> arr;
	vector<int> len;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (i - a >= 0) arr.push_back({ i - a, a });
	}
	sort(arr.begin(), arr.end());
	for (auto& x : arr) {
		int t = x.second;
		if (len.empty() || t > len.back()) len.emplace_back(t);
		else {
			auto j = lower_bound(len.begin(), len.end(), t) - len.begin();
			len[j] = t;
		}
	}
	cout << len.size() << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while (t--) solve();
	return 0;
}
