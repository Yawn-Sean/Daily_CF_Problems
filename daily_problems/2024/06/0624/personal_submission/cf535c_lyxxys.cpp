#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5, inf = 1e9;

// O(mlogn)
void solve(){   
    int A, B, m;
    ll lp, t, n;
    cin >> A >> B >> m;
    vector <ll> a(N), Pre(N+1);
    for (ll i = 1; i <= N; ++ i) a[i] = A + (i-1)*B, Pre[i] = Pre[i-1]+a[i];

    function<bool(int)> check = [&](int mid){
        return a[mid] <= t && t*n >= Pre[mid]-Pre[lp-1];
    };

    while (m--){
        cin >> lp >> t >> n;
        int l = lp, r = N;
        while (l < r){
            int mid = l+r+1 >> 1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        if (a[r] <= t) cout << l << "\n";
        else cout << -1 << "\n";
    }
}

