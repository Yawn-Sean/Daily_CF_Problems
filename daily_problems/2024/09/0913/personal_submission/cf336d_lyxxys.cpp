#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int pows(long long a, int b){
    long long res = 1;
    while (b){
        if (b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n, m, g;
    cin >> n >> m >> g;
    vector <long long> fact(n+m+1), inv(n+m+1);
    fact[0] = 1;
    for (int i = 1; i <= n+m; ++ i) fact[i] = fact[i-1]*i%mod;
    inv[n+m] = pows(fact[n+m], mod-2);
    for (int i = n+m; i >= 1; -- i) inv[i-1] = inv[i]*i%mod;

    auto mods = [&](int x)->int{
        return (x%mod + mod)%mod;
    };
    auto comb = [&](int a, int b)->int{
        return fact[a]*inv[a-b]%mod *inv[b]%mod;
    };

    // cur 是当前要构造的数字
    function<int(int,int,int)> recur = [&](int n, int m, int cur){
        if (n==0) return m > 1 ? int(cur == 0) : int(cur == 1);
        if (m==0) return n%2 ? int(cur == 0) : int(cur == 1);
        if (cur == 1) return mods(comb(n+m, n) - recur(n, m, 0));
        else return (comb(n+m-1, m-1) + recur(n-1, m, 1))%mod;
    };

    int res = recur(n, m, g);
    cout << res << "\n";
}
