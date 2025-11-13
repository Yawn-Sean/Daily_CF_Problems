#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


struct p {
    int l, r, sum;
};

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> nums(n + 5);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    int base = (1 << 31) - 1;
    for (int i = 1; i <= n; i++) if ((nums[i] | k) != nums[i]) nums[i] = base;
    vector<p> tr(4 * n);
    auto pushup = [&](int x) -> void {
        tr[x].sum = tr[x * 2].sum & tr[x * 2 + 1].sum;
    };

    auto build = [&](auto build, int x, int l, int r) -> void {
        tr[x].l = l, tr[x].r = r;
        if (l == r) {tr[x].sum = nums[l]; return;}
        int mid = (l + r) >> 1;
        build(build, x * 2, l, mid), build(build, x * 2 + 1, mid + 1, r);
        pushup(x);
    };

    auto query = [&](auto query, int x, int l, int r) -> int {
        if (tr[x].l >= l && tr[x].r <= r) return tr[x].sum;
        int mid = (tr[x].l + tr[x].r) >> 1;
        int sum = base;
        if (l <= mid) sum &= query(query, x * 2, l, r);
        if (mid < r) sum &= query(query, x * 2 + 1, l, r);
        return sum;
    };

    build(build, 1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (query(query, 1, l, r) == k) cout << "YES" << endl;
        else cout << "NO" << endl;
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