#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e5+5, inf = (1u<<31)-1, mod = 998244353;
const double eps = 1e-9;

void solve(){

    int n;
    cin >> n;
    vector <int> nums(n+1), digitsum(11), Pre(11), pow10(25, 1);
    for (int i = 1; i <= n; ++ i){
        cin >> nums[i];
        int len = 0, x = nums[i];
        while (x){
            x /= 10;
            ++ len;
        }
        ++ digitsum[len];
    }
    for (int i = 1; i <= 24; ++ i) {
        pow10[i] = 10ll * pow10[i - 1] % mod;
    }
    for (int i = 1; i <= 10; ++ i)
        Pre[i] = Pre[i-1] + digitsum[i];

    ll res = 0;
    for (int i = 1; i <= n; ++ i){
        vector <int> digs;
        int x = nums[i];
        digs.push_back(0);
        while (x){
            digs.push_back(x%10);
            x /= 10;
        }
        int m = digs.size()-1;

        for (int u = 1; u <= m; ++ u){
            int dig = digs[u];
            int cnt = Pre[10]-Pre[u-1];
            res += 11ll*dig*pow10[2*u-2]%mod*cnt%mod, res %= mod;
            for (int j = 1; j < u; ++ j) {
                res += 2ll * dig * digitsum[j] * pow10[u+j-1] % mod, res %= mod;
            }
        }
    }

    cout << res << "\n";
}
