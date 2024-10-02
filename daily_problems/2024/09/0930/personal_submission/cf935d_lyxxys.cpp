#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    const int mod = 1e9+7;
    int n, m;
    cin >> n >> m;
    vector <ll> inv(m+1);
    inv[1] = 1;
    for (int i = 2; i <= m; ++ i){
        inv[i] = (mod - mod/i) * inv[mod%i] % mod;
    }

    vector <int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    long long res = 0, mom = 1, b = (m-1)*inv[m]%mod * inv[2] % mod;

    for (int i = 0, jg = 0; i < n; ++ i){
        if (B[i] > 0 && A[i] > 0){  // 如果都不为 0，讨论前面有没有 0 出现 和 A与B 的关系
            if (B[i] > A[i]) break;
            else if (B[i] != A[i]){
                if (jg) res += mom % mod, res %= mod;
                else res = 1;
                break;
            } else continue;
        }
        if (A[i]==0&&B[i]==0){
            res += b * mom % mod;
        } else if (A[i]==0){
            res += (m-B[i]) * inv[m]%mod * mom % mod;
        } else if (B[i]==0){
            res += (A[i]-1) * inv[m]%mod * mom % mod;
        }
        res %= mod;
        mom = mom * inv[m] % mod;
        jg = 1;
    }

    cout << res << "\n";
}
 
