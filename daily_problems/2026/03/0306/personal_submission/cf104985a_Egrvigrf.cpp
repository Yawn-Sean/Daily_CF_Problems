#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    double v, t;
    int id;
};

void solve() {
    int n;
    cin >> n;
    vector<node> a(n);
    double tot_v = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].v >> a[i].t;
        a[i].id = i;
        tot_v += a[i].v;
    }

    sort(a.begin(),a.end(),[](node x, node y) {
        return x.t < y.t;
    });

    vector<double> ans(n);
    double cur_v = tot_v;
    double cur = 0.0;
    double tt = 0.0;
    for (auto i : a) {
        double ex_t = (i.t * i.v - tt * i.v) / (i.v * tot_v / cur_v);
        cur += ex_t;
        tt = i.t;
        cur_v -= i.v;
        ans[i.id] = cur;
    }
    for (auto i : ans) {
        cout << fixed << setprecision(7) << i << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
       solve();
    }
    return 0;
}