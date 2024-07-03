#include <iostream>
#include <vector>
using namespace std;
#define int long long

int mod = 1e9 + 7;
auto mul(auto a, auto b) {
	vector<vector<int>> ret(2, vector<int>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
			}
		}
	}
	return ret;
}
auto pw(vector<vector<int>> dp, int b) {
	auto ret = dp;
	while (b) {
		if (b & 1) ret = mul(ret, dp);
		b >>= 1;
		dp = mul(dp, dp);
	}
	return ret;
}
int pw(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}

void yrlpSolve() {
	int n, k, l; cin >> n >> k >> l >> mod;
	if ((l < 63 && 1LL << l <= k) || mod == 1) {
		cout << 0 << endl;
		return;
	}
	vector<vector<int>> dp(2, vector<int>(2, 1)); dp[1][1] = 0;
	dp = pw(dp, n - 1);
	int p0 = (dp[0][0] + dp[0][1]) % mod;
	int p1 = (pw(2, n) + mod - p0) % mod;
	int ans = 1;
	for (int i = 0; i < l; i++) {
		ans = ans * (k >> i & 1 ? p1 : p0);
		ans %= mod;
	}
	cout << ans << endl;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
