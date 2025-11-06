#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;
const int64 PHI = MOD - 1; 

long long modString(const string &s, long long m) {
    long long res = 0;
    for (char c : s) {
        if (c < '0' || c > '9') continue; 
        res = (res * 10 + (c - '0')) % m;
    }
    return res;
}

int64 modpow(int64 a, long long e) {
    a %= MOD;
    int64 r = 1;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    char op;
    cin >> x >> op >> y;

    long long xm = modString(x, MOD);
    long long ym = modString(y, MOD);

    if (op == '+') {
        long long ans = xm + ym;
        if (ans >= MOD) ans -= MOD;
        cout << ans << "\n";
    } else if (op == '-') {
        long long ans = xm - ym;
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    } else if (op == '*') {
        long long ans = (__int128)xm * ym % MOD;
        cout << ans << "\n";
    } else if (op == '^') {
        if (xm == 0) {
            cout << 0 << "\n";
        } else {
            long long exp_mod = modString(y, PHI);
            cout << modpow(xm, exp_mod) << "\n";
        }
    } else {
        return 0;
    }

    return 0;
}
