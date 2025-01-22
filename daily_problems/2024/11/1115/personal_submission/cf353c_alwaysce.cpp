#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	i64 ans = 0, pre_mx = 0, suf_tot = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		suf_tot += a[i];
	}
	
	string s;
	cin >> s;
	
	// 01011
	// 1 2 10 0 17
	// 
	for (int i = n - 1; i >= 0; i--) {
		suf_tot -= a[i];

		i64 cur_1 = (pre_mx + (s[i] - '0') * a[i]); // pick
		i64 cur_2 = cur_1;
		if (s[i] == '1') {
			cur_2 = pre_mx + suf_tot;
		} // not_pick

		ans = max(ans, max(cur_1, cur_2));
		pre_mx = cur_1;
	}
	cout << ans;
    return 0;
}
