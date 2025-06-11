#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

const int maxn = 1e5+7;
int dp[maxn][55];
int inline red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), k = red(), p = red();
    ve<int> a(n), pre(n + 1);
    generate(all(a), red);
    rep(i, 1, n + 1) {
        a[i - 1] %= p;
        pre[i] = (pre[i - 1] + a[i - 1]) % p;
    }
    memset(dp, -127, sizeof(dp));
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, k + 1) {
            rep(o, 0, p) {
                dp[pre[i]][j] = max(dp[pre[i]][j], dp[o][j-1] + (pre[i] - o + p) % p);
            }
        }
    }
    cout << dp[pre[n]][k] << '\n';


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
https://codeforces.com/problemset/problem/958/C2
*/