#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    vector <int> ys1(n), ys2(m), ls(m);
    vector <int> ids1(n), ids2(m);
    for (auto &x : ys1) cin >> x;
    for (auto &x : ys2) cin >> x;
    for (auto &x : ls) cin >> x;

    iota(ids1.begin(), ids1.end(), 0);
    iota(ids2.begin(), ids2.end(), 0);
    sort(ids1.begin(), ids1.end(), [&](int &u, int &v){
        return ys1[u] < ys1[v];
    });
    sort(ids2.begin(), ids2.end(), [&](int &u, int &v){
        return ys2[u] < ys2[v];
    });

    f64 mi = inf_i64;
    array <int,2> ans = {-1,-1};
    auto chk = [&](int i, int j)->f64{
        i = ids1[i], j = ids2[j];
        i64 y1 = ys1[i], y2 = ys2[j], l = ls[j];
        f64 val = l + sqrtl((b-a)*(b-a)+(y1-y2)*(y1-y2)) + sqrtl(a*a+y1*y1);
        if (val < mi){
            mi = val;
            ans = {i, j};
        }
        return val;
    };
    for (int j = 0; j < m; ++ j){
        int lo = 0, hi = n-1;
        while (lo < hi){
            int m = (hi-lo)/3;
            int m1 = lo + m, m2 = hi - m;
            if (chk(m2, j) > chk(m1, j)) hi = m2 - 1;
            else lo = m1 + 1;
        }
        chk(lo, j);
    }

    cout << ans[0]+1 << " " << ans[1]+1 << "\n";
}
