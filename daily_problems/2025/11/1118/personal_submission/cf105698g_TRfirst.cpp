#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



struct node {
    int l, r, mn;
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<node> tr(4 * n);

    auto pushup = [&](int x) -> void {
        tr[x].mn = min(tr[2 * x].mn, tr[2 * x + 1].mn);
    };

    auto build = [&](auto build, int x, int l, int r) -> void {
        tr[x].l = l, tr[x].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(build, 2 * x, l, mid);
        build(build, 2 * x + 1, mid + 1, r);
    };

    auto change = [&](auto change, int now, int x, int k) -> void {
        if (tr[now].l == tr[now].r) {tr[now].mn = k; return;}
        int mid = (tr[now].l + tr[now].r) >> 1;
        if (x <= mid) change(change, 2 * now, x, k);
        else change(change, 2 * now + 1, x, k);
        pushup(now);
    };

    auto query = [&](auto query, int u, int x, int l, int r) -> int {
        if (tr[u].mn >= x) return -1;
        if (tr[u].l == tr[u].r) return tr[u].l;
        else if (l <= tr[u].l && tr[u].r <= r){
            if (tr[2 * u + 1].mn < x) return query(query, 2 * u + 1, x, l, r);
            else return query(query, 2 * u, x, l, r);
        } 
        else {
            int mid = (tr[u].l + tr[u].r) >> 1;
            int res = -1;
            if (r > mid) res = query(query, 2 * u + 1, x, l, r);
            if (res == -1 && l <= mid) res = query(query, 2 * u, x, l, r);
            return res;
        }
    };

    build(build, 1, 1, n);

    vector<int> mx(n + 5);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            if (mx[l] < r) {
                mx[l] = r;
                change(change, 1, l, r);
            }
        }
        else {
            int pos;
            cin >> pos;
            int res = query(query, 1, pos, 1, pos);
            if (res == -1) cout << pos + 1 << endl;
            else cout << pos - res + 1 << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}