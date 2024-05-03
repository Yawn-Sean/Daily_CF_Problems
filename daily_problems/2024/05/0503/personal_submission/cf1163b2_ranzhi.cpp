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

int get_init(vector<int> &arr) {
	int maxn = 0;
	unordered_map<int, int> mp, cnt;
	for (int i = 0; i < arr.size(); i++) {
		mp[arr[i]] += 1;
		int t = mp[arr[i]] - 1;
		if (cnt.count(t)) {
			cnt[t] -= 1;
			if (cnt[t] == 0) cnt.erase(t);
		}
		cnt[t + 1] += 1;
		if (cnt.size() > 2) continue;
		if (cnt.size() == 2) {
			auto p = cnt.begin();
			auto q = ++cnt.begin();
			if (p->second - 1 == 0) {
				if (p->first - 1 == 0 || p->first - 1 == q->first) maxn = i + 1;
			}
			if (q->second - 1 == 0) {
				if (q->first - 1 == 0 || q->first - 1 == p->first) maxn = i + 1;
			}
		}
		else if (cnt.begin()->first == 1 || cnt.begin()->second == 1) maxn = i + 1;
	}
	return maxn;
}

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << get_init(arr) << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while (t--) solve();
	return 0;
}
