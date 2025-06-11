#include <iostream>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int dp[1 << 20] {};
int cnt[1 << 20] {};
void yrlpSolve() {
    int n, mod; cin >> n >> mod;
    dp[1] = 1;
    int s1 = 1, s2 = 0;
    for (int i = 2; i <= n; i++) {
    	dp[i] = s1;
    	for (int j = 2; j * j <= i; j++) {
    		if (i % j == 0) {
    			s2 -= dp[cnt[j]++];
    			s2 += dp[cnt[j]];
    			if (i / j != j) {
    				s2 -= dp[cnt[i / j]++];
    				s2 += dp[cnt[i / j]];
				}
				s2 += mod, s2 %= mod;
			}
		}
		s2 += 1, cnt[i] += 1;
		dp[i] += s2, dp[i] %= mod;
		s1 += dp[i], s1 %= mod;
	}
	cout << dp[n] << endl; 
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
