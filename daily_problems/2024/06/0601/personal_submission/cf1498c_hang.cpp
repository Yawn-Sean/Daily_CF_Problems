#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int N = 1001;
const int K = 1001;
int n, k;
const int mod = 1e9 + 7;
int dp[N][K][2];

int f(int curr, int k, int dir) {
    if (k == 1) return 1;

    if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2; 
    if (dir == 1) {
        if (curr < n) ans += f(curr + 1, k, dir) - 1;
        ans %= mod;
        if (curr > 1) ans += f(curr - 1, k - 1, 1 - dir) - 1;
        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1) ans += f(curr - 1, k, dir) - 1;
        ans %= mod;
        if (curr < n) ans += f(curr + 1, k - 1, 1 - dir) - 1;
        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << f(1, k, 1) << endl;
    }
}