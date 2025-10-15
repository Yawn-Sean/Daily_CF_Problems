#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int64 modpow(int64 a, int64 e){
    int64 r = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
int64 modinv(int64 a){ return modpow((a%MOD+MOD)%MOD, MOD-2); }

struct Fenwick {
    int n;
    vector<int64> bit;
    Fenwick(int n_=0): n(n_), bit(n_+1, 0) {}
    void add(int idx, int64 val){
        val %= MOD;
        if(val < 0) val += MOD;
        while(idx <= n){
            bit[idx] += val;
            if(bit[idx] >= MOD) bit[idx] -= MOD;
            idx += idx & -idx;
        }
    }
    int64 sum(int idx){
        int64 r = 0;
        while(idx > 0){
            r += bit[idx];
            if(r >= MOD) r -= MOD;
            idx -= idx & -idx;
        }
        return r % MOD;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    string ps;
    if(!(cin >> n >> q >> ps)) return 0;

    long long p_num = 0, p_den = 1;
    auto pos = ps.find('.');
    if(pos == string::npos){
        p_num = stoll(ps);
        p_den = 1;
    } else {
        string intpart = ps.substr(0, pos);
        string frac = ps.substr(pos+1);
        string both = intpart + frac;
        p_num = stoll(both);
        p_den = 1;
        for(size_t i=0;i<frac.size();++i) p_den *= 10;
    }
    long long r_num = p_den - p_num;
    long long r_den = p_den;

    int64 r_mod = ( (r_num % MOD) * modinv(r_den % MOD) ) % MOD;
    int64 inv_r_mod = modinv(r_mod);
    vector<int64> pow_r(n+1), pow_inv(n+1);
    pow_r[0] = 1;
    pow_inv[0] = 1;
    for(int i=1;i<=n;++i){
        pow_r[i] = pow_r[i-1] * r_mod % MOD;
        pow_inv[i] = pow_inv[i-1] * inv_r_mod % MOD;
    }

    Fenwick ft_inv(n), ft_fwd(n);

    for(int i=0;i<q;++i){
        char op;
        cin >> op;
        if(op == '+'){
            long long b; int x;
            cin >> b >> x;
            b %= MOD;
            int64 v1 = b * pow_inv[x] % MOD;
            int64 v2 = b * pow_r[x] % MOD;
            ft_inv.add(x, v1);
            ft_fwd.add(x, v2);
        } else if(op == '-'){
            long long b; int x;
            cin >> b >> x;
            b %= MOD;
            int64 v1 = b * pow_inv[x] % MOD;
            int64 v2 = b * pow_r[x] % MOD;
            ft_inv.add(x, (MOD - v1) % MOD);
            ft_fwd.add(x, (MOD - v2) % MOD);
        } else if(op == '?'){
            int x; cin >> x;
            int64 sumLeft = ft_inv.sum(x); // sum_{y<=x} b_y r^{-y}
            int64 term1 = pow_r[x] * sumLeft % MOD;
            int64 sumAllFwd = ft_fwd.sum(n);
            int64 sumToX = ft_fwd.sum(x);
            int64 sumRight = (sumAllFwd - sumToX + MOD) % MOD; // sum_{y>x} b_y r^{y}
            int64 term2 = pow_inv[x] * sumRight % MOD;
            int64 ans = (term1 + term2) % MOD;
            cout << ans << '\n';
        }
    }
    return 0;
}
