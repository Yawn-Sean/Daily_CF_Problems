#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf = 1e9;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		有1-n+1的房间
		
		1<=n<=10^3
		
		pi(1<=pi<=i) 注意到pi<=i只会往前走
		
		第偶数次进入同一个房间i 就会走P[i]
		奇数次走到 就会走到 i + 1 房间
		
		问到达n+1房间的最小移动次数
	*/
	int n;
	cin >> n;
	
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	
	// dp[i] = dp[i - 1] + 1 + dp[i - 1] - dp[p[i - 1]] + 1
	vector<int> dp(n + 2);
	dp[1] = 0;
	for (int i = 2; i <= n + 1; i++) {
		dp[i] = (2ll * dp[i - 1] % mod - dp[p[i - 1]] % mod + mod + 2ll) % mod;
	}
	cout << dp[n + 1] % mod;
	
    return 0;
}
