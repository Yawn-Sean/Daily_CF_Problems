#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

const int MOD = 1e9 + 7;

ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res % MOD;
}

void solve() { 
    ll a, b, n, x; cin >> a >> b >> n >> x;
    if (a == 1) cout << (x + n % MOD * b) % MOD << endl;
    else {
        ll res = ksm(a, n) * x % MOD;
        res += (ksm(a, n) - 1) * ksm(a - 1, MOD - 2) % MOD * b;
        cout << (res % MOD + MOD) % MOD << endl;
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
