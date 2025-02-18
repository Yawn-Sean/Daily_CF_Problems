#include <bits/stdc++.h>
using namespace std;
struct fenwick{
    vector <int> info;
    int n;
    fenwick(){}
    fenwick(int n): n(n), info(n+1){}
    void add(int i, int c){
        while (i <= n){
            info[i] += c;
            i += i&-i;
        }
    }
    long long ask(int i){
        long long res = 0;
        while (i){
            res += info[i];
            i -= i&-i;
        }
        return res;
    }
};

void solve(){
    const int mod = 998244353, N = 2e5+1;
    int n, m;
    cin >> n >> m;
    vector <long long> fact(N), inv(N), finv(N);
    vector <int> cnt(N), s(n+1), t(m+1);
    fact[0] = 1, inv[1] = 1;
    for (int i = 1; i < N; ++ i)
        fact[i] = fact[i-1]*i % mod;
    for (int i = 2; i < N; ++ i)
        inv[i] = (mod - mod/i) * inv[mod%i] % mod;
    auto pows = [&](long long a, int b)->long long{
        long long res = 1;
        while (b){
            if (b&1) res = res*a%mod;
            a = a*a%mod;
            b >>=1;
        }
        return res;
    };
    finv[N-1] = pows(fact[N-1], mod-2);
    for (int i = N-1; i >= 1; -- i){
        finv[i-1] = finv[i]*i%mod;
    }

    fenwick Y(N);  
    for (int i = 1; i <= n; ++ i){
        cin >> s[i];
        Y.add(s[i], 1);
        cnt[s[i]] += 1;
    }
    for (int i = 1; i <= m; ++ i) cin >> t[i];

    long long res = 0, mom = 1;
    for (int i = 1; i < N; ++ i){
        if (cnt[i] > 1){
            mom = mom * finv[cnt[i]] % mod;
        }
    }

    for (int i = 1; i <= min(n, m); ++ i){
        long long sz = Y.ask(t[i]-1);
        res += sz * fact[n-i] %mod * mom %mod;
        res %= mod;
        // 不可以凑出字典序相同的
        if (cnt[t[i]] == 0) break;
        // 删去字典序相同贡献，修改前缀积, 前缀和
        Y.add(t[i], -1);
        long long c = cnt[t[i]];
        mom = mom * cnt[t[i]] % mod;
        cnt[t[i]] -= 1;
        // 特判最短公共串相同
        if (i==n && n < m) res = (res + 1) %mod;
    }

    cout << res << "\n";
}
 
