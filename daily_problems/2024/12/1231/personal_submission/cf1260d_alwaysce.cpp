#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k, t;
	cin >> m >> n >> k >> t;
	
	vector<int> a(m), ls(k), rs(k), d(k);
	for(auto&x: a) { cin >> x; }
	for (int i = 0; i < k; i++) {
		cin >> ls[i] >> rs[i] >> d[i];
	}
	
	sort(a.rbegin(), a.rend());
	
	vector<int> diff(n + 1, 0);
	int left = 1, right = m + 1;
	int ans = 0;
	
	auto check = [&](int x) {
		for (int i = 0; i < k; i++) {
			// 解除陷阱 然后从r折返到l-1 在一起从l-1回到r 
			if (a[x - 1] < d[i]) {
				diff[ls[i] - 1]++;
				diff[rs[i]]--;
			}
		}
		int tot = n + 1, cur = 0;
		for (int i = 0; i <= n; i++) {
			cur += diff[i];
			if (cur > 0) {
				tot += 2;
			}
			diff[i] = 0;
		}
		return tot <= t;
	};
	
	while (left < right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	cout << ans;
	return 0;
}
