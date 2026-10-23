#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	ll ans = 0;
	int full = (1 << n) - 1;
	for(int k = 0; k < 31; ++k){
		vector<vector<int>> dp(1 << n,vector<int>(2,0));
		dp[0][0] = 1;
		for(int mask = 0; mask < (1 << n); ++mask){
			int i = __builtin_popcount(mask);
			if(i == n) continue;
			for(int parity = 0; parity < 2; ++parity){
				for(int j = 0; j < n; ++j){
					if(mask & (1 << j)) continue;
					int bit = ((a[j] + b[i]) >> k) & 1;
					int new_parity = parity ^ bit;
					int &ref = dp[mask | (1 << j)][new_parity];
					ref = (ref + dp[mask][parity]) % MOD;
				}
			}
		}
		ll cnt = dp[full][1];
		ans = (ans + cnt * (1ll << k)) % MOD;
	}
	cout << ans << '\n';

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}