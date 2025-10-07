#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const long long MOD = 998244353;

long long norm(long long x){ x %= MOD; if (x < 0) x += MOD; return x; }

long long modpow(long long a, long long e){
    long long r = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1) r = (__int128)r * a % MOD;
        a = (__int128)a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long K;
    if(!(cin >> N >> K)) return 0;

    vector<long long> a(N), b(N);
    long long Sa = 0, Sb = 0, s = 0;

    for(int i = 0; i < N; ++i){
        long long x; cin >> x;
        a[i] = norm(x);
        Sa += a[i]; if (Sa >= MOD) Sa -= MOD;
    }
    for(int i = 0; i < N; ++i){
        long long x; cin >> x;
        b[i] = norm(x);
        Sb += b[i]; if (Sb >= MOD) Sb -= MOD;
        s += a[i] * b[i] % MOD; if (s >= MOD) s -= MOD;
    }

    long long ans;
    if(K == 0){
        ans = N % MOD;
    }else{
        long long c = modpow(s % MOD, K - 1);
        ans = (__int128)c * Sa % MOD * Sb % MOD;
    }
    cout << ans % MOD << "\n";
    return 0;
}
