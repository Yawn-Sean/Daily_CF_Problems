#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



struct p {
    int l, r, sum;
};

void solve(){
    int n = 1;
    while (1) {
        cin >> n;
        if (n == 0) return;
        vector<vector<int>> pos(n + 5);
        for (int i = 1; i <= 2 * n; i++) {
            int num;
            cin >> num;
            pos[num].push_back(i);
        }
        vector<pair<int, int>> ps;
        for (int i = 1; i <= n; i++) {
            int k = pos[i].size() / 2;
            for (int j = 0; j < k; j++) {
                ps.push_back({pos[i][j], pos[i][j + k]});
            }
        }
        sort(ps.begin(), ps.end());
        vector<p> tr(8 * n);

        auto pushup = [&](int x) -> void {
            tr[x].sum = tr[2 * x].sum + tr[2 * x + 1].sum;
        };

        auto build = [&](auto build, int x, int l, int r) -> void {
            tr[x].l = l, tr[x].r = r;
            if (l == r) return;
            int mid = (l + r) >> 1;
            build(build, x * 2, l, mid), build(build, x * 2 + 1, mid + 1, r);
        };

        auto query = [&](auto query, int x, int l, int r) -> int {
            if (tr[x].l >= l && tr[x].r <= r) return tr[x].sum;
            int mid = (tr[x].l + tr[x].r) >> 1;
            int sum = 0;
            if (l <= mid) sum += query(query, x * 2, l, r);
            if (mid < r) sum += query(query, x * 2 + 1, l, r);
            return sum;
        };

        auto change = [&](auto change, int now, int x, int k) -> void {
            if (tr[now].l == tr[now].r) {tr[now].sum = k; return;}
            int mid = (tr[now].l + tr[now].r) >> 1;
            if (x <= mid) change(change, now * 2, x, k);
            else change(change, now * 2 + 1, x, k);
            pushup(now);
        };

        build(build, 1, 1, 2 * n);
        ll ans = 1ll * n * (n - 1) / 2;
        for (int i = 0; i < n; i++) {
            ans -= query(query, 1, ps[i].first, ps[i].second);
            change(change, 1, ps[i].second, query(query, 1, ps[i].second, ps[i].second) + 1);
        }
        cout << ans << endl;
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