#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>; 

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> res(n + 1);
    vector dp(n, vector<int>(n));
    rep(i, 0, n) {
        dp[i][i] = 1;
    }
    rep(i, 0, n - 1) {
        dp[i][i + 1] = (s[i] == s[i + 1] ? 2 : 0);
    }
    rep(it, 3, n + 1) {
        rep(l, 0, n - it + 1) {
            int r = l + it - 1;
            if (s[l] != s[r] || !dp[l + 1][r - 1]) {
                dp[l][r] = 0;
                continue;
            }
            int m = (l + r) >> 1;
            if (it & 1) {
                dp[l][r] = dp[l][m - 1] + 1;
            } else {
                dp[l][r] = dp[l][m] + 1;
            }
        }
    }

    rep(it, 1, n + 1) {
        rep(l, 0, n - it + 1) {
            res[dp[l][l + it - 1]]++;
        }
    }

    per(i, n - 1, 1) {
        res[i] += res[i + 1];
    }

    rep(i, 1, n + 1) {
        cout << res[i] << " \n"[i == n];
    }
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

/*
https://codeforces.com/problemset/problem/835/D
*/
