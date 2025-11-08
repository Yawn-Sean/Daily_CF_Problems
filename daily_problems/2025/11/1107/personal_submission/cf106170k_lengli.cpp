#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> ls(m), rs(m);
    vector<ll> xs(m), ys(m);
    for (int i = 0; i < m; ++i) {
        int l, r; ll x, y;
        cin >> l >> r >> x >> y;
        ls[i] = l - 1; 
        rs[i] = r;  
        xs[i] = x;
        ys[i] = y;
    }
    
    const ll BOUND = (ll)1e13;
    ll L = 0, R = BOUND;
    vector<ll> sol(n + 1, 0);
    
    while (L <= R) {
        ll mid = (L + R) >> 1;
        fill(sol.begin(), sol.end(), 0);
        for (int it = 0; it < n; ++it) {
            for (int j = 0; j < m; ++j) {
                sol[rs[j]] = max(sol[rs[j]], sol[ls[j]] + xs[j]);
                sol[ls[j]] = max(sol[ls[j]], sol[rs[j]] - ys[j]);
            }
            for (int i = 0; i < n; ++i) {
                ll low = max(1LL, nums[i] - mid); 
                sol[i + 1] = max(sol[i + 1], sol[i] + low);
                sol[i] = max(sol[i], sol[i + 1] - nums[i] - mid);
            }
        }
        
        bool flg = true;
        for (int i = 0; i < n; ++i) {
            ll low = max(1LL, nums[i] - mid);
            ll high = nums[i] + mid;
            ll diff = sol[i + 1] - sol[i];
            if (!(low <= diff && diff <= high)) {
                flg = false;
                break;
            }
        }

        if (flg) {
            for (int j = 0; j < m; ++j) {
                ll diff = sol[rs[j]] - sol[ls[j]];
                if (!(xs[j] <= diff && diff <= ys[j])) {
                    flg = false;
                    break;
                }
            }
        }
        
        if (flg) R = mid - 1;
        else L = mid + 1;

    }
    
    if (L < BOUND) cout << L << '\n';
    else cout << -1 << '\n';
    
    return 0;
}
