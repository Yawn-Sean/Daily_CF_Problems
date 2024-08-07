#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 998244353, inf = 1e9;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> nums(n), f(63);

    for (auto &y : nums){
        cin >> y;
        for (int i = 0; i < 31; ++ i){
            if (y>>i & 1){
                f[i] += 1;
            }
        }
    }

    ll res = 0;
    for (auto &y : nums){
        for (int i = 0; i < 31; ++ i)
            if (y>>i & 1)
                f[i] -= 1;

        ll z = y;
        for (int i = 0; i < k; ++ i)
            z = z*x;
        
        ll ans = 0;

        for (int i = 0; i < 63; ++ i){
            if (!f[i] && z>>i & 1) ans += 1ll << i;
            if (f[i]) ans += 1ll << i;
        }

        res = max(res, ans);
        for (int i = 0; i < 31; ++ i)
            if (y>>i & 1)
                f[i] += 1;
    }

    cout << res << "\n";
}
