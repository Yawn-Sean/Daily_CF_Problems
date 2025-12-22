#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, p, inf = 1e9;
    cin >> n >> p;

    p = min(p, 20);
    vector<vector<int>> dp(p + 1, vector<int>(n + 1, 1));

    for (int i = 1; i <= p; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = min(dp[i - 1][j - 1] + dp[i][j - 1], inf);
        }
    }

    for (int i = 0; i <= n; i ++) {
        if (dp[p][i] >= n) {
            cout << i;
            break;
        }
    }

	return 0;
}