#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<i64> a(n), b(n);
	map<i64, int> cnt;
	for (auto& x: a) {
		cin >> x;
		cnt[x]++;
	}
	for (auto& x: b) { cin >> x; }
	
	vector<int> used(n);
	i64 ans = 0;
	for (auto& pr: cnt) {
		if (pr.second > 1) {
			for (int i = 0; i < n; i++) {
				if (!used[i] and (a[i] & pr.first) == a[i]) {
					used[i] = 1;
					ans += b[i];
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
