#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2, MOD))

const int maxN = 1e3 + 7;
const int MOD = 1e9 + 7;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);

int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = finv[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        f[i] = i * f[i-1] % MOD;
    }
    finv[maxN] = ksm(f[maxN], MOD-2);
    for (int i = maxN-1; i >= 1; i--) {
        finv[i] = finv[i+1] * (i+1) % MOD;
    }
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] * finv[n - m] % MOD;
}

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = '#' + s;

    vector<int> cnt(30);
    int x = 0;
    for (int i = 1; i <= n; i++) {
        char c = s[i];
        if (c == '?') x++;
        else cnt[c - 'a' + 1]++;
    }

    int fz = 0;
    vector<vector<int>> dp(30, vector<int>(x + 1, 0));

    //for (int j = 0; j <= x; j++) dp[0][j] = 1;
    dp[0][0]=1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k + j <= x; k++) {
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j] * finv[cnt[i] + k] % MOD * finv[k] % MOD) % MOD;
                // cout << dp[i][j + k] << endl;
            }
        }
    }
    cout << dp[26][x] * f[n] % MOD * f[x] % MOD * ksm(ksm(26, MOD-2), x) % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}