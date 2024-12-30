#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<i64> a(n);
	for (auto& v: a) { cin >> v; }
	
	vector<i64> suf_cnt(n), suf_need(n);
	vector<i64> pre_cnt(n), pre_need(n);
	
	for (int i = n - 1; i > 0; i--) {
		suf_need[i - 1] = max(suf_need[i] + 1, a[i]);
		suf_cnt[i - 1] = suf_cnt[i] + (suf_need[i - 1] - a[i]);
	}
	
	for (int i = 0; i < n - 1; i++) {
		pre_need[i + 1] = max(pre_need[i] + 1, a[i]);
		pre_cnt[i + 1] = pre_cnt[i] + (pre_need[i + 1] - a[i]);
	}
	i64 ans = 1e18;
	for (int i = 0; i < n; i++) {
		ans = min(ans, pre_cnt[i] + suf_cnt[i] + max(0ll, max(pre_need[i], suf_need[i]) + 1 - a[i]));
	}
	cout << ans;
	return 0;
}
