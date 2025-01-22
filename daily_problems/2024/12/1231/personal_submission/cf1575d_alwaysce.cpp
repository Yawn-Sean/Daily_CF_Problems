#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	int n = s.size();
	
	if (n == 1) {
		if ((s[0] == '0' or s[0] == 'X' or s[0] == '_')) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		bool hasX = false;
		for (auto& c: s) {
			hasX |= (c == 'X');
		}
		
		int ans = 0;
		for (int x = 0; x < 10; x++) {
			if (x >= 1 and not hasX) {
				break;
			}
			
			vector<int> dp(25, 0), ndp(25, 0);
			dp[0] = 1;
			for (int i = 0; i < n; i++) {
				if (s[i] != '_') {
					int d = (s[i] != 'X' ? s[i] - '0' : x);
					if (not (i == 0 and d == 0)) {
						for (int mod = 0; mod < 25; mod++) {
							ndp[(mod * 10 + d) % 25] += dp[mod];
						}
					}
				} else {
					for (int d = 0; d < 10; d++) {
						if (i == 0 and d == 0) {
							continue;
						}
						for (int mod = 0; mod < 25; mod++) {
							ndp[(mod * 10 + d) % 25] += dp[mod];
						}
					}
				}
				
				for (int mod = 0; mod < 25; mod++) {
					dp[mod] = ndp[mod];
					ndp[mod] = 0;
				}
			}
			ans += dp[0];
		}
		cout << ans;
	}
	return 0;
}
