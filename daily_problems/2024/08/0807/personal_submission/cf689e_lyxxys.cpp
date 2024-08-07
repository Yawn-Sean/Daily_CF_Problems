#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <array<int,2>> segs(n);
    vector <int> dic;
    for (auto &it : segs){
        cin >> it[0] >> it[1];
        dic.push_back(it[0]), dic.push_back(it[1]+1);
    }
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    
    auto find = [&](int x)->int{
        return lower_bound(dic.begin(), dic.end(), x) - dic.begin() + 1;
    };

    int len = dic.size();
    vector <int> dif(len+1);
    for (auto &it : segs){
        int l = find(it[0]), r = find(it[1]+1);
        dif[l] += 1, dif[r] -= 1;
    }
    for (int i = 1; i <= len; ++ i)
        dif[i] += dif[i-1];

    // return;
    vector <int> C(n+1), fact(n+1), finv(n+1);
    auto div = [&](ll x)->int{
        int p = mod-2;
        ll res = 1;
        while (p){
            if (p&1) res = res*x%mod;
            x = x*x%mod;
            p >>= 1;
        }
        return res;
    };
    fact[0] = 1;
    for (ll i = 1; i <= n; ++ i)
        fact[i] = i*fact[i-1]%mod;
    finv[n] = div(fact[n]);
    for (ll i = n-1; i >= 0; -- i)
        finv[i] = finv[i+1] * (i+1) % mod;
    // 预处理 C(i,k)
    for (int i = k; i <= n; ++ i){
        C[i] = 1ll * fact[i] * finv[i-k]%mod * finv[k] %mod;
    }

    ll res = 0;
    for (int i = 1; i < len; ++ i){
        ll cnt = dic[i]-dic[i-1];
        (res += cnt*C[dif[i]]%mod) %= mod;
    }

    cout << res << "\n";
}
