#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m, x, i;
	cin >> n >> m >> x;
	x--;
	vector<bool> dp(n, false);
	dp[x] = true;
	while (m--) {
		int r;
		char c;
		cin >> r >> c;
		vector<bool> new_dp(n, false);
		for (i = 0; i < n; ++i) {
			if (dp[i]) {
				if (c == '0' || c == '?') {
					new_dp[(i + r) % n] = true;
				}
				if (c == '1' || c == '?') {
					new_dp[(i + n - r) % n] = true;
				}
			}
		}
		swap(dp, new_dp);
	}
	vector<int> res;
	for (i = 0; i < n; ++i) {
		if (dp[i]) res.emplace_back(i);
	}

	cout << res.size() << '\n';
	for (i = 0; i < res.size(); ++i) {
		cout << res[i] + 1 << ' \n'[i == res.size() - 1];
	}
}
 
int main() {  
	cin.tie(nullptr)->sync_with_stdio(false);
  	
  	int t;
  	cin >> t;

  	while (t--) {
  		solve();
  	}

    return 0;  
}