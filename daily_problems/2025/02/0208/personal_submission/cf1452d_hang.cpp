#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long modExp(long long base, long long exp){
    long long res = 1 % MOD;
    base %= MOD;
    while(exp > 0){
        if(exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> dp(n+1), pre(n+1);
    dp[0] = 1; dp[1] = 1;
    pre[0] = 1; pre[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = pre[i-1] % MOD;
        pre[i] = (dp[i] + pre[i-2]) % MOD;
    }
    long long p2n = modExp(2, n);
    // Modular inverse of p2n is p2n^(MOD-2) mod MOD
    long long invp2n = modExp(p2n, MOD-2);
    cout << (dp[n] % MOD) * (invp2n % MOD) % MOD << "\n";
    return 0;
}