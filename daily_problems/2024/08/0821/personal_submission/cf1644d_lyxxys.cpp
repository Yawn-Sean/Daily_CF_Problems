#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5+11, mod = 998244353, inf = 1e9;

int pows(ll a, int b){
    ll res = 1;
    while (b){
        if (b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return (int)res;
}
int rows[N], cols[N];

void solve(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector <array<int,2>> qs(q);
    for (auto &[x, y] : qs) cin >> x >> y;
    int sz = 0, c1 = 0, c2 = 0;
    for (int i = q-1; i >= 0; -- i){
        auto &[x, y] = qs[i];
        if (!rows[x] || !cols[y]){
            ++ sz;
            if (!rows[x]) ++ c1;
            if (!cols[y]) ++ c2;
            rows[x] += 1, cols[y] += 1;
        }
        if (c1 == n || c2 == m) break;
    }

    cout << pows(k, sz) << "\n";
    for (int i = q-1; i >= 0; -- i){
        auto &[x, y] = qs[i];
        rows[x] = 0;
        cols[y] = 0;
    }
}
