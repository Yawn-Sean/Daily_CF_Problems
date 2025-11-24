#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 2000005;

long long f[MAXN];
long long g[MAXN]; 
long long inv[MAXN]; 

void precompute() {
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        inv[i] = (MOD - (long long)(MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
    f[1] = 1;
    g[1] = 1;

    
    long long S_g = 0; 
    long long S_f = 0;
    long long H = 0;
    
    long long SS_g = 1; 
    long long SS_f = 1; 
    
    
    long long prev_S_g = 0;
    long long prev_S_f = 0;
    long long prev_H = 0;
    long long prev_g = 1;
    long long prev_f = 1;
    
    long long inv2 = inv[2];

    for (int n = 2; n < MAXN; n++) {
        long long cur_S_g = (prev_S_g + SS_g + prev_g) % MOD;
        long long cur_S_f = (prev_S_f + SS_f + prev_f) % MOD;
        
        long long cur_H = (prev_H + prev_S_g + prev_g) % MOD;
        long long K_inv = (2 * inv[n - 1]) % MOD;
        K_inv = (K_inv * inv[n + 2]) % MOD;
        g[n] = (1 + cur_S_g * K_inv) % MOD;

        long long term1 = ((long long)(n + 1) * inv2) % MOD;
        long long term2 = ((cur_S_f + cur_H) % MOD * K_inv) % MOD;
        f[n] = (term1 + term2) % MOD;

        SS_g = (SS_g + g[n]) % MOD;
        SS_f = (SS_f + f[n]) % MOD;
        prev_S_g = cur_S_g;
        prev_S_f = cur_S_f;
        prev_H = cur_H;
        prev_g = g[n];
        prev_f = f[n];
    }
}

void solve() {
    int l, r;
    if (!(cin >> l >> r)) return;
    int len = r - l + 1;
    long long term = ((long long)(l - 1) * g[len]) % MOD;
    long long ans = (f[len] + term) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
