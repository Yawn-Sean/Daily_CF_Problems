#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXM = 200000;

long long modpow(long long a, long long e){
    long long r = 1;
    while(e){
        if(e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> inv(MAXM + 1, 0);
    for(int i = 1; i <= MAXM; ++i){
        inv[i] = modpow(i, MOD - 2);
    }

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            long long x;
            cin >> x;
            sum = (sum + x) % MOD;
        }
        long long ans = sum * inv[n] % MOD;
        cout << ans << "\n";
    }

    return 0;
}
