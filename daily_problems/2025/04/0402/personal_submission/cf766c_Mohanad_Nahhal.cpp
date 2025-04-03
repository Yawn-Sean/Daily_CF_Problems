/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    const int mod = 1e9 + 7;
    vector c(26, 0);
    vector num(26, vector(n + 1, 0));
    for (int i = 0; i < 26; i ++) cin >> c[i];

    for (int i = 0; i < n; i ++) {
        num[s[i] - 'a'][i] ++;
        if (i) {
            for (int j = 0; j < 26; j ++) num[j][i] += num[j][i - 1];
        }
    }
    
    auto ck = [&] (int x, int y) {
        for (int i = 0; i < 26; i ++) {
            int cnt = num[i][y];
            if (x) cnt -= num[i][x - 1];
            if (cnt && y - x + 1 > c[i]) return 0;
        }
        return 1;
    };

    vector dp(n + 1, -1);
    function<int(int)> f = [&] (int x) {
        if (x == n) return 1;
        if (dp[x] != -1) return dp[x];
        int ans = 0;
        for (int i = x; i < n; i ++) {
            if (ck(x, i)) ans = (ans + f(i + 1)) % mod;
        }
        return dp[x] = ans;
    };
    cout << f(0) << endl;

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {
            if (ck(i, j)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;

    dp.assign(n + 1, -1);
    function<int(int)> ff = [&] (int x) {
        if (x == n) return 0;
        if (dp[x] != -1) return dp[x];
        int ans = 1e7;
        for (int i = x; i < n; i ++) {
            if (ck(x, i)) ans = min(ans, ff(i + 1) + 1) % mod;
        }
        return dp[x] = ans;
    };
    cout << ff(0) << endl;
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
