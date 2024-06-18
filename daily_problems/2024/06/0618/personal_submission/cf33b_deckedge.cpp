#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
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
    string sa, sb;
    cin >> sa >> sb;
    int n = red(); 
    const int inf = 1e9;
    ve dp(26, ve<int>(26, inf));
    rep(i, 0, 26) {
        dp[i][i] = 0;
    }
    while (n--) {
        char c1, c2;
        int d;
        cin >> c1 >> c2 >> d;
        int x1 = c1 - 'a', x2 = c2 - 'a';
        dp[x1][x2] = min(dp[x1][x2], d);
    }
    if (sa.size() != sb.size()) {
        cout << "-1\n";
        return ;
    }
    rep(k, 0, 26) {
        rep(i, 0, 26) {
            rep(j, 0, 26) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ve res(26, ve<int>(26, inf));
    ve tmp(26, ve<int>(26, -1));

    rep(k, 0, 26) {
        rep(i, 0, 26) {
            rep(j, 0, 26) {
                if (dp[i][j] + dp[k][j] < res[i][k]) {
                    res[i][k] = dp[i][j] + dp[k][j];
                    tmp[i][k] = j;
                }
            }
        }
    }

    int len = sa.size(), sum = 0;
    string fin_str(len, 'a');
    rep(i, 0, len) {
        int x = sa[i] - 'a', y = sb[i] - 'a';
        if (tmp[x][y] == -1) {
            cout << "-1\n";
            return ;
        }
        sum += res[x][y];
        fin_str[i] += tmp[x][y];
    }
    cout << sum << '\n' << fin_str << '\n';
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
https://codeforces.com/problemset/status?my=on
*/