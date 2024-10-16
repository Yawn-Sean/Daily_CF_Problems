#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, m, b;
    cin >> n >> m >> b;
    const int all = (1<<m) - 1;
    vector <int> own(n+1), moni(n+1), cost(n+1), p(n+1);

    int st_all = 0;
    for (int i = 1, r; i <= n; ++ i){
        cin >> cost[i] >> moni[i] >> r;
        int cur = 0;
        for (int j = 0, z; j < r; ++ j){
            cin >> z;
            cur |= 1 << z-1;
        }
        own[i] = cur;
        st_all |= cur;
    }
    iota(p.begin(), p.end(), 0);
    sort(p.begin()+1, p.end(), [&](int x, int y){
        return moni[x] < moni[y];
    });

    if (st_all != all){
        cout << -1 << "\n";
        return;
    }

    ll res = 4e18;
    vector <long long> f(1<<m, res);
    f[0] = 0;
    for (int i = 1; i <= n; ++ i){
        int i1 = p[i];
        ll st = own[i1], c = cost[i1], c1 = moni[i1];
        for (int j = 0; j < 1<<m; ++ j){
            f[j|st] = min(f[j|st], f[j] + c);
        }
        if (f[all] + c1*b < res){
            res = f[all] + c1*b;
        }
    }

    cout << res << "\n";
}
