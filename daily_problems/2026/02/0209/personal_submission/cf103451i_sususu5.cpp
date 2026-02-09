#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e5;
const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

vector<ll> fact;
void precomputeFact(int n) {
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

ll qpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll modInverse(ll n) {
    return qpow(n, MOD - 2);
}

ll comb(int n, int k) {
    return fact[n] * modInverse(fact[k]) % MOD * modInverse(fact[n - k]) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    
    int m = a.size();
    ll saved = qpow(2, n - 1);
    ll ans = 1;
    for (int i = 0; i < m; i++) {
        ll res = 0;
        if (a[i] == '1') {
            if (b[i] == '1' && n % 2 == c[i] - '0') {
                res = 1;
            }
        } else {
            if (b[i] == '0') {
                if (c[i] == '0') res = 1;
            } else {
                if (n >= 2) {
                    res = saved;
                    if (c[i] == '0') res = (res + MOD - 1) % MOD;
                    if (n % 2 == c[i] - '0') res = (res + MOD - 1) % MOD;
                }
            }
        }
        ans = 1LL * ans * res % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}