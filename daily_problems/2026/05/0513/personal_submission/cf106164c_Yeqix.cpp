#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	int x;
	cin >> x;
	for (int i = 1; i <= 1000; i++) {
		vector<int> ans(i + 1);
		iota(ans.begin() + 1, ans.end(), 1);
		i64 res = i * (i + 1) / 2 - x;
		for (int j = i; j >= 2; j--) {
			if (res - 2 * j >= 0 && res - 2 * j != 2) {
				res -= 2 * j;
				ans[j] = -ans[j];
			}
		}

		if (!res) {
			cout << i << "\n";
			for (int j = 1; j <= i; j++) {
				if (j > 1 && ans[j] > 0) {
					cout << "+";
				}
				cout << ans[j];
			}
			cout << "\n";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
