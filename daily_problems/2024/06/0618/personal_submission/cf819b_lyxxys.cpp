#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005000, inf = 0x3f3f3f3f, P = 998244353;

ll f[N];
void solve(){
    int n;
    cin >> n;
    vector <ll> a(n+1), dif1(2*n+1), dif2(2*n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    for (int i = 1; i <= n; ++ i){
        // int id = (a[i]-i+n)%n;
        int l = n+a[i]-i, r = 2*n-i;
        ++ dif1[l], -- dif1[r+1];
        dif2[l] -= l, dif2[r+1] += l;
    }
    for (int i = 0; i < 2*n; ++ i)
        dif1[i+1] += dif1[i], dif2[i+1] += dif2[i];

    for (int i = 0; i < 2*n; ++ i)
        f[i%n] += 1ll*dif1[i]*i + dif2[i];
    // for (int i = 0; i < n; ++ i) cout << f[i] << "\n";
    ll res = 0, cost = 2e18;
    for (int i = 0; i < n; ++ i)
        if (cost > f[i])
            cost = f[i], res = i;
    
    cout << 2*cost << " " << res << "\n";
}
