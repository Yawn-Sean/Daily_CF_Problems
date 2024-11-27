#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+7;
    auto pows = [&](long long a, int b)->int{
        long long res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };

    int n, k;
    cin >> n >> k;
    vector <int> fact(n+1, 1), invs(n+1), A(n);
    for (auto &x : A) cin >> x;
    for (int i = 1; i <= n; ++ i){
        fact[i] = 1ll * fact[i-1] * i % mod;
    }
    invs[n] = pows(fact[n], mod-2);
    for (int i = n; i >= 1; -- i){
        invs[i-1] = 1ll*invs[i]*i % mod;
    }

    vector <int> res;
    for (int i = 0; i < n; ++ i){
        long long ans = A[i], sons = k;
        for (int j = i-1, d = 1; j >= 0; -- j){
            ans += 1ll * A[j] * sons % mod * invs[d] % mod;
            if (ans >= mod) ans -= mod;
            sons = sons*(k+d) % mod;
            d += 1;
        }
        res.push_back(ans);
    }

    assert(res.size() == n);
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}
