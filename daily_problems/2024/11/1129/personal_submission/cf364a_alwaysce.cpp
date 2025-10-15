#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a;
	cin >> a;
	string s;
	cin >> s;
	
	int n = s.size();
	map<int,i64> cnt;
	i64 ans = 0;
	for (int l = 0; l < n; l++) {
		int tmp = 0;
		for (int r = l; r < n; r++) {
			tmp += (s[r] - '0');
			cnt[tmp]++;
		}
	}	

	if (a != 0) {
		for (auto& pr: cnt) {
			int x = pr.first;
			if (x != 0 and a % x == 0) {
				ans += 1ll * pr.second * cnt[a / x];
			}
		}
	} else {
		i64 tot = 0;
		for (auto& pr: cnt) { tot += pr.second; }
		for (auto& pr: cnt) {
			if (pr.first == 0) {
				ans += 1ll * pr.second * tot;
			} else {
				ans += 1ll * cnt[0] * pr.second;
			}
		}
	}
	cout << ans;	
	return 0;
}

