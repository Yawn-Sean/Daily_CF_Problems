#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n, cnt[26], dp[3000][3000];
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> s;
	n = s.length();
	
	if(n < 3000) {
		for(int i = 0; i < n; ++ i) dp[i][i] = 1;
		for(int len = 2; len <= n; ++ len) {
			for(int l = 0; l + len <= n; ++ l) {
				int r = l + len - 1;
				dp[l][r] = max({dp[l][r], dp[l][r - 1], dp[l + 1][r]});
				if(s[l] == s[r]) {
					dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 2);
				}
			}
		}
		int l = 0, r = n - 1, tag = 0;
		string ans;
		while(l <= r) {
			if(s[l] == s[r]) {
				ans += s[l];
				if(l == r) tag = 1;
				++ l;
				-- r;
			}
			else {
				if(dp[l][r] == dp[l + 1][r]) ++ l;
				else -- r;
			}
		}
		
		if(ans.length() > 50) ans = ans.substr(0, 50), tag = 0;
		string t = ans.substr(0, ans.length() - tag);
		
		reverse(t.begin(), t.end());
		cout << ans + t;
	}
	else {
		for(int i = 0; i < n; ++ i) {
			if(++ cnt[s[i] - 'a'] == 100) {
				for(int j = 1; j <= 100; ++ j) cout << s[i];
				exit(0);
			}
		}
	}
	return 0;
}
