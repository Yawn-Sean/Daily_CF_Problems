#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;
    int n, m;
    cin >> n >> m;
    vector <int> xs(n);
    vector <ary2> lrs;
    for (auto &x : xs) cin >> x;
    for (auto &it : lrs) cin >> it[0] >> it[1];
    vector <int> ans(n), p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int u, int v){
        return xs[u] < xs[v];
    });
    for (int i = 0; i < n; ++ i){
        ans[p[i]] = i%2;
    }
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
