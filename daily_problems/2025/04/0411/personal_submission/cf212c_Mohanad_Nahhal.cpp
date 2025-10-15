/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    map<vector<int>, long long> dp;
    function<long long(int, int, int, int, int)> f = [&] (int i, int last, int cur, int a, int b) {
        if (i == s.size()) return 1ll;
        if (dp.count({i, last, cur, a, b})) return dp[{i, last, cur, a, b}];
        long long ans = 0;
        if (i != s.size() - 1) {
            for (int next = 0; next <= 1; next ++) {
                int val = s[i] - 'A';
                if (!val && !cur && !next) ans += f(i + 1, cur, next, a, b);
                if (!val && cur && !last) ans += f(i + 1, cur, next, a, b);
                if (val && !cur && next) ans += f(i + 1, cur, next, a, b);
                if (val && cur && last) ans += f(i + 1, cur, next, a, b);
            }
        }
        else if(cur == a) {
            int val = s[i] - 'A', next = b;
            if (!val && !cur && !next) ans += f(i + 1, cur, next, a, b);
            if (!val && cur && !last) ans += f(i + 1, cur, next, a, b);
            if (val && !cur && next) ans += f(i + 1, cur, next, a, b);
            if (val && cur && last) ans += f(i + 1, cur, next, a, b);
        }
        return dp[{i, last, cur, a, b}] = ans;
    };

    long long ans = 0;
    for (int i = 0; i <= 1; i ++) {
        for (int j = 0; j <= 1; j ++) ans += f(0, i, j, i, j);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
