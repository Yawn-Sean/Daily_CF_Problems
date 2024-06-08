#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>; 
const int mod = 998244353;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    vector<int> a(n);
    vector<int64_t> dp(5001, 0);
    generate(all(a), red);
    sort(all(a));
    dp[0] = 1;
    int64_t cur = 0, res = 0;
    rep(i, 0, n) {
        per(j, cur, 0) {
            if (dp[j] > 0) {
                res = (res + (dp[j] * max((j + a[i] + 1) / 2, a[i])) % mod) % mod;
                dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % mod;  
            }
        }
        cur += a[i];
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

/*
dp[x]为当前总数为x的方案数
首先，分组数量x需要满足2x>=总个数，同时，分组数量也需要满足x>=最大频率。于是 
x >= max((i + num + 1) / 2, num) num为当前最大频率，(i + num + 1) / 2为总个数一半向上取整数
*/