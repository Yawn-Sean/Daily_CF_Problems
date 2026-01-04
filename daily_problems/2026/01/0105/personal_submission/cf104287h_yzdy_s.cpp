#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 1e9 + 7;
int ksm(int a, int b, int MOD) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int d;cin >> d;
    int res = 0;
    int n = (ksm(2, d, MOD) - 1 + MOD) % MOD;
    for (int i = 1; i < d; i++) {
        int a = (ksm(2, i, MOD) - 1 + MOD) % MOD;
        int b = (n - a + MOD) % MOD;
        res = (res + ksm(2, d - i + 1, MOD) * a % MOD * b) % MOD;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}