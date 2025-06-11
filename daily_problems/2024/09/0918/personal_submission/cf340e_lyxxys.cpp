#include <bits/stdc++.h>
using namespace std;

void solve(){
    const int mod = 1e9+7;
    int n;
    cin >> n;
    vector <vector<long long>> C(n+1, vector<long long>(n+1));
    for (int i = 0; i <= n; ++ i){
        C[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    vector <long long> nums(n), fact(n+1), used(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++ i) fact[i] = fact[i-1] * i % mod;
    for (auto &x : nums){
        cin >> x;
        if (x > 0) used[x] = 1;
    }

    int x = 0, y = 0;
    for (int i = 1; i <= n; ++ i){
        if (!used[i]){
            if (nums[i-1] < 0) x += 1;
            else y += 1;
        }
    }

    int ans = 0;
    for (int i = 0, mark=1; i <= x; ++ i, mark = -mark){
        ans += mark * fact[x+y-i] * C[x][i] % mod;
        ans = (ans%mod + mod)%mod;
    }
    cout << ans << "\n";
}
 
