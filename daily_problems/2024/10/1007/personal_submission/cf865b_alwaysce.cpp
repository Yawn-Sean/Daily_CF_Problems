#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n, tot;
	cin >> n >> tot;
	
	vector<pair<int,int>> v1, v2;
	i64 cnt1 = 0, cnt2 = 0, ans = 0;
	
	while (n--) {
		int s, a, b;
		cin >> s >> a >> b;
		if (a >= b) {
			ans += 1ll * s * a;
			v1.push_back({a - b, s});
			cnt1 += s;
		} else {
			ans += 1ll * s * b;
			v2.push_back({b - a, s});
			cnt2 += s;
		}
	}
	
	// 没有超出的
	if ((cnt1 + tot - 1) / tot + (cnt2 + tot - 1) / tot == (cnt1 + cnt2 + tot - 1) / tot) {
		cout << ans;
	} else {
		sort(v1.begin(), v1.end());
		int rem1 = (cnt1 % tot);
		i64 val1 = 0;
		for (auto& pr: v1) {
			int c = min(pr.second, rem1);
			rem1 -= c;
			val1 += 1ll * c * pr.first;
		}
		
		sort(v2.begin(), v2.end());
		int rem2 = (cnt2 % tot);
		i64 val2 = 0;
		for (auto& pr: v2) {
			int c = min(pr.second, rem2);
			rem2 -= c;
			val2 += 1ll * c * pr.first;
		}
		
		cout << ans - min(val1, val2);
	}
	
	return 0;
}
