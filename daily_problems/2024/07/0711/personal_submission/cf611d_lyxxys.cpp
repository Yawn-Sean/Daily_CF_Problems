#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9 + 7, inf = 1e9;
/*
f[i][j] 以i作开头j结尾的方案数量
f[i][j] = sigma {f[k][i-1] | k <= j-1, digit(s[k~i-1]) < digit(s[i~j])}
*/
void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> f(n + 1, vector<int>(n + 1)), lcp(n + 2, vector<int>(n + 2)), Sum(n + 1, vector<int>(n+1));

    s = " " + s;
    for (int i = n; i >= 1; -- i){
        for (int j = n; j >= 1; -- j){
            if (s[i] == s[j])
                lcp[i][j] = lcp[i+1][j+1] + 1;
        }
    }
    auto check = [&](int x, int y) -> bool{
        if (lcp[x][y] >= y - x)
            return false;
        return ((int)s[x+lcp[x][y]] < (int)s[y+lcp[x][y]]);
    };
    // 枚举右端点和左端点
    for (int i = 1; i <= n; ++i)
        f[1][i] = 1;

    for (int j = 1; j <= n; ++ j){
        for (int i = 1; i <= j; ++ i){
            if (s[i] == '0')
                continue;
            int l = max(0, i - (j - i + 1)); // l~i-1
            f[i][j] = (f[i][j] + Sum[i-1][i-1] - Sum[l][i-1] + mod) % mod;
            if (check(l, i))
                f[i][j] = (f[i][j] + f[l][i - 1]) % mod;
        }
        for (int i = 1; i <= j; ++ i)
            Sum[i][j] = (Sum[i-1][j] + f[i][j]) % mod;
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res + f[i][n]) % mod;
//        cout << f[i][n] << "\n";
    }
    cout << res << "\n";
}
