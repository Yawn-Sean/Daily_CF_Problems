/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

int dp[2002][4001][2];
void solve() {
   memset(dp, -1, sizeof dp);
    vector a(0, 0);
    vector b(4001, vector(0, 0));
    for (int i = 1; i <= 4000; i ++) {
        a.push_back(2);
        while (a.size() != 1) {
            int n = a.size();
            if (a[n - 1] == a[n - 2]) {
                int val = a.back();
                a.pop_back();
                a.pop_back();
                a.push_back(val * 2);
            }
            else break;
        }
        b[i] = a;
    }

    const int mod = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    int target = (1 << k);

    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    b[0].push_back(1);

    function<int(int, int, int)> f = [&] (int x, int num, int did) {
        if (b[num][0] >= target) did = 1;
        if (x == n + 1) return did;
        if (dp[x][num][did] != -1) return dp[x][num][did];
        int ans = 0;
        if (a[x]) {
            if (a[x] == 2) ans = (ans + f(x + 1, num + 1, did)) % mod;
            else {
                if (b[num].back() != 2) ans = (ans + f(x + 1, num + 2, did)) % mod;
                else ans = (ans + f(x + 1, 2, did)) % mod;
            }
        }
        else {
            ans = (ans + f(x + 1, num + 1, did)) % mod;
            if (b[num].back() != 2) ans = (ans + f(x + 1, num + 2, did)) % mod;
            else ans = (ans + f(x + 1, 2, did)) % mod;
        }
        return dp[x][num][did] = ans;
    };
    cout << f(1, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
