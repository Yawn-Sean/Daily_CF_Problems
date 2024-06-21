#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;
    vector <ll> p(n+1), a(n+1), b(n+1);
    iota(p.begin(), p.end(), 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i] >> b[i];

    sort(p.begin()+1, p.end(), [&](int i, int j){
        return a[i]-b[i] > a[j]-b[j];
    });

    ll res = 0;
    for (int i = 1; i <= n; ++ i){
        int pos = p[i];
        res += a[pos]*(i-1) + b[pos]*(n-i);
    }

    cout << res << "\n";
}
