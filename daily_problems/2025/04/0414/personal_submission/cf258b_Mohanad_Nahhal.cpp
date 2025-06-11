/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    const int mod = 1e9 + 7;
    cin >> m;

    string s;
    int mm = m;
    while (mm) {
        s.push_back(mm % 10 + '0');
        mm /= 10;
    }
    reverse(s.begin(), s.end());    

    vector dp(10, vector(10, vector(2, -1)));
    function<int(int, int, int)> f = [&] (int x, int num, int on) {
        if (num < 0) return 0;
        if (x == s.size()) {
            if (num) return 0;
            return 1;
        }
        if (dp[x][num][on] != -1) return dp[x][num][on];
        int ans = 0, c = s[x] - '0';
        for (int i = 0; i <= 9; i ++) {
            if (on && i > c) break;
            int del = ((i == 4) || (i == 7)), nexton = on;
            if (i < c) nexton = 0;
            ans += f(x + 1, num - del, nexton);
        }
        return dp[x][num][on] = ans;
    };

    vector num(10, 0);
    for (int i = 0; i <= 9; i ++) num[i] = f(0, i, 1);
    num[0] --;

    int ans = 0;

    function<long long(int, int)> ff = [&] (int x, int sum) {
        if (sum <= 0) return 0ll;
        if (x == 0) return 1ll;
        long long ans = 0;
        
        for (int i = 0; i <= 9; i ++) {
            if (num[i] == 0) continue;
            num[i] --;
            ans = (ans + ff(x - 1, sum - i) * (num[i] + 1)) % mod;
            num[i] ++;
        }
        return ans;
    };

    for (int i = 0; i <= 9; i ++) {
        if (num[i] == 0) break;
        num[i] --;
        ans = (ans + ff(6, i) * (num[i] + 1)) % mod;
        num[i] ++;
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
