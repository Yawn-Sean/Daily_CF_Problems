#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

const int N = 1e3 + 7, mod = 1e9 + 7;
int dp[N];
int64_t C[N][N];

inline int red() {
    int x;
    cin >> x;
    return x;
}

void init() {
    rep(i, 0, 1001) {
        C[i][0] = 1;
    }
    rep(i, 1, 1001) {
        rep(j, 1, 1001) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int ones(int n) {
    int res = 0;
    while (n) {
        if (n & 1) {
            res++;
        }
        n >>= 1;
    }
    return res;
}

void solve() {
    string s;
    int k;
    cin >> s >> k;
    init();
    int n = s.size();
    dp[1] = 0;
    rep(i, 2, 1001) {
        dp[i] = dp[ones(i)] + 1;
    }
    if (!k) {
        cout << "1\n";
        return ;
    }
    int64_t cnt = 0, res = 0;
    rep(i, 0, n) {
        if (s[i] == '0') {
            continue;
        }
        rep(j, max(cnt, 1ll), 1000) {
            if (dp[j] == k - 1) {
                res = (res + C[n - i - 1][j - cnt]) % mod;
            }
        }
        cnt++;
    }
    cnt = 0;
    for (char c : s) {
        if (c == '1') {
            cnt++;
        }
    }
    if (dp[cnt] == k - 1) {
        res = (res + 1) % mod;
    }
    if (k == 1) {
        res = (res + mod - 1) % mod;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0; 
}