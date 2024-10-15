#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int mod = 998244353, N = 1e6+1;
    int n;
    cin >> n;
    vector <vector<int>> A(n+1);
    vector <long long> Ct(N), prob(N), inv(N);
    for (int i = 1, k; i <= n; ++ i){
        cin >> k;
        A[i].resize(k+1);
        for (int j = 1; j <= k; ++ j){
            cin >> A[i][j];
            ++ Ct[A[i][j]];
        }
    }

    inv[1] = 1;
    for (int i = 2; i < N; ++ i){
        inv[i] = (mod - mod/i) * inv[mod%i] % mod;
    }
    for (int i = 1; i < N; ++ i) prob[i] = Ct[i]*inv[n]%mod;

    long long res = 0;
    for (int i = 1; i <= n; ++ i){
        int k = A[i].size()-1;
        for (int j = 1; j <= k; ++ j){
            int x = A[i][j];
            res += inv[n] * inv[k]%mod * prob[x]%mod;
            res %= mod;
        }
    }

    cout << res << "\n";
}
 
